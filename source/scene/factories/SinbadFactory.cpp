/*
 * =====================================================================================
 *
 *       Filename:  SinbadFactory.cpp
 *
 *    Description:
 *
 *        Created:  28/05/2017 13:22:44
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <OgreSkeletonInstance.h>
#include <OgreTrays.h>

#include "AnimationListComponent.hpp"
#include "AttackBehaviour.hpp"
#include "BehaviourComponent.hpp"
#include "CollisionComponent.hpp"
#include "EasyBehaviour.hpp"
#include "EntityListComponent.hpp"
#include "GamePadMovement.hpp"
#include "HudBehaviour.hpp"
#include "MovementComponent.hpp"
#include "HealthComponent.hpp"
#include "LifetimeComponent.hpp"
#include "PlayerMovementBehaviour.hpp"
#include "SceneNodeComponent.hpp"
#include "SinbadFactory.hpp"
#include "ScoreComponent.hpp"

SceneObject SinbadFactory::create() {
	SceneObject object("Sinbad", "Player");
	object.set<ScoreComponent>();

	auto &collisionComponent = object.set<CollisionComponent>(std::vector<std::string>{"Body", "Sword1", "Sword2"});
	collisionComponent.addAction(&SinbadFactory::swordAction);

	auto &healthComponent = object.set<HealthComponent>(500);
	object.set<LifetimeComponent>([&] (SceneObject &object) {
		return healthComponent.life() == 0;
	});

	auto &bodyNodeComponent = object.set<SceneNodeComponent>(Ogre::Vector3(20, CHAR_HEIGHT, 20), Ogre::Vector3(0.5, 0.5, 0.5));
	auto &entityListComponent = object.set<EntityListComponent>(bodyNodeComponent.node);
	bodyNodeComponent.node->setFixedYawAxis(true);

	auto &movementComponent = object.set<MovementComponent>(new GamePadMovement);
	movementComponent.behaviour.reset(new PlayerMovementBehaviour({"IdleTop", "IdleBase"}, {"RunTop", "RunBase"}));

	auto &behaviourComponent = object.set<BehaviourComponent>();
	behaviourComponent.addBehaviour<EasyBehaviour>("SoundEffect", [] (SceneObject &object) {
		auto &animationListComponent = object.get<AnimationListComponent>();
		const char *activeAnimation = animationListComponent.getActiveAnimation(0);

		static bool soundPlayed = false;
		if (activeAnimation == std::string("SliceHorizontal") || activeAnimation == std::string("SliceVertical")) {
			if (animationListComponent.isAnimationBetween(activeAnimation, 60, 70) && !soundPlayed) {
				AudioPlayer::playEffect("attack_melee1");
				soundPlayed = true;
			}
			else if (animationListComponent.isAnimationBetween(activeAnimation, 0, 60) && soundPlayed) {
				soundPlayed = false;
			}
		}
		else {
			soundPlayed = false;
		}
	});

	auto &attackBehaviourA = behaviourComponent.addBehaviour<AttackBehaviour>("AttackA", "SliceVertical");
	attackBehaviourA.setCondition([] (SceneObject &object) {
		return GamePad::isKeyPressed(GameKey::A);
	});

	auto &attackBehaviourB = behaviourComponent.addBehaviour<AttackBehaviour>("AttackB", "SliceHorizontal");
	attackBehaviourB.setCondition([] (SceneObject &object) {
		return GamePad::isKeyPressed(GameKey::B);
	});

	auto *trayManager = OgreData::getInstance().trayManager();
	behaviourComponent.addBehaviour<HudBehaviour>("hud", trayManager->createProgressBar(OgreBites::TL_LEFT, "PlayerBar_" + object.name(), object.name(), 200, 100));


	Ogre::Entity *bodyEntity = entityListComponent.addEntity("SinbadBody", "Sinbad.mesh", true);
	bodyEntity->getSkeleton()->setBlendMode(Ogre::ANIMBLEND_CUMULATIVE);

	entityListComponent.addEntity("SinbadSword1", "Sword.mesh");
	entityListComponent.addEntity("SinbadSword2", "Sword.mesh");
	entityListComponent.linkEntityToBone("SinbadSword1", "SinbadBody", "Handle.L");
	entityListComponent.linkEntityToBone("SinbadSword2", "SinbadBody", "Handle.R");

	const char *animNames[] = {
		"IdleBase", "IdleTop", "RunBase", "RunTop", "HandsClosed", "HandsRelaxed", "DrawSwords",
		"SliceVertical", "SliceHorizontal", "Dance", "JumpStart", "JumpLoop", "JumpEnd"
	};

	auto &animationListComponent = object.set<AnimationListComponent>();
	for (const char *animName : animNames) {
		animationListComponent.add(bodyEntity, animName);
	}

	animationListComponent.setAnimationEndCallback("SliceVertical", std::bind(&AttackBehaviour::animationEndCallback, &attackBehaviourA, std::placeholders::_1, std::placeholders::_2));
	animationListComponent.setAnimationEndCallback("SliceHorizontal", std::bind(&AttackBehaviour::animationEndCallback, &attackBehaviourB, std::placeholders::_1, std::placeholders::_2));

	animationListComponent.setLoop("SliceHorizontal", false);
	animationListComponent.setLoop("SliceVertical", false);
	animationListComponent.enableAnimation("HandsClosed");
	animationListComponent.setActiveAnimation(0, "IdleTop");
	animationListComponent.setActiveAnimation(1, "IdleBase");

	return object;
}

void SinbadFactory::swordAction(SceneObject &sinbad, SceneObject &object, const CollisionInfo &infos) {
	if (infos.inCollision && (infos.entityName1 == "Sword1" || infos.entityName1 == "Sword2") &&
	    ((sinbad.get<AnimationListComponent>().getActiveAnimation(0) == std::string("SliceHorizontal") &&
	      sinbad.get<AnimationListComponent>().isAnimationBetween("SliceHorizontal", 70, 90)) ||
	     (sinbad.get<AnimationListComponent>().getActiveAnimation(0) == std::string("SliceVertical") &&
	      sinbad.get<AnimationListComponent>().isAnimationBetween("SliceVertical", 70, 90)))) {
		if (object.type() == "Enemy" && !object.get<LifetimeComponent>().dead(object) &&
		    (!object.has<AnimationListComponent>() || object.get<AnimationListComponent>().getActiveAnimation(0) != std::string("Hit"))) {
			auto &healthComponent = object.get<HealthComponent>();
			healthComponent.removeLife(50);

			if (healthComponent.life() == 0) {
				AudioPlayer::playEffect("vocal_monster2");
				if (object.has<AnimationListComponent>())
					object.get<AnimationListComponent>().setActiveAnimation(0, "Die", true)->timer.setTime(6);
				object.remove<MovementComponent>();
			}
			else if (object.has<AnimationListComponent>() && object.get<AnimationListComponent>().isAnimationFinished("Hit")) {
				object.get<AnimationListComponent>().setActiveAnimation(0, "Hit", true)->timer.setTime(6);
			}
		}
	}
}

