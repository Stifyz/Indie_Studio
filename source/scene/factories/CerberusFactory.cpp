/*
 * =====================================================================================
 *
 *       Filename:  BerserkerFactory.cpp
 *
 *    Description:
 *
 *        Created:  05/06/2017 22:16:12
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <functional>

#include "AnimationListComponent.hpp"
#include "AttackBehaviour.hpp"
#include "CerberusFactory.hpp"
#include "CerberusAttackBehaviour.hpp"
#include "BehaviourComponent.hpp"
#include "CollisionComponent.hpp"
#include "DamageComponent.hpp"
#include "EnemyMovement.hpp"
#include "EntityListComponent.hpp"
#include "HealthComponent.hpp"
#include "LifeBarBehaviour.hpp"
#include "LifetimeComponent.hpp"
#include "MovementComponent.hpp"
#include "PlayerMovementBehaviour.hpp"
#include "RadarComponent.hpp"
#include "SceneNodeComponent.hpp"

#include "GamePadMovement.hpp"

static unsigned long int cerberusCount = 0;

SceneObject CerberusFactory::create(const Ogre::Vector3 &pos) {
	SceneObject object("Cerberus" + std::to_string(cerberusCount++), "Enemy");
	object.set<CollisionComponent>();
	object.set<RadarComponent>("any", "Player");
	object.set<DamageComponent>(15);

	auto &healthComponent = object.set<HealthComponent>(1000, 1000, 200);
	object.set<LifetimeComponent>([&] (SceneObject &object) {
		return healthComponent.life() == 0;
	});

	auto &bodyNodeComponent = object.set<SceneNodeComponent>(pos, Ogre::Vector3(0.3, 0.3, 0.3));
	bodyNodeComponent.node->setFixedYawAxis(true);

	auto &entityListComponent = object.set<EntityListComponent>(bodyNodeComponent.node);
	Ogre::Entity *bodyEntity = entityListComponent.addEntity(object.name() + "Body", "Cerberus.mesh", true);

	auto &behaviourComponent = object.set<BehaviourComponent>();
	behaviourComponent.addBehaviour<LifeBarBehaviour>("LifeBar", bodyNodeComponent.root, Ogre::Vector3(0, 6, 0));
	// auto &cerberusAttackBehaviour = behaviourComponent.addBehaviour<CerberusAttackBehaviour>("Fight");
	// cerberusAttackBehaviour.setCondition([] (SceneObject &object) {
	// 	return object.get<RadarComponent>().neareastObjectDistance <= 10;
	// });

	// auto &movementComponent = object.set<MovementComponent>(new GamePadMovement);
	auto &movementComponent = object.set<MovementComponent>(new EnemyMovement);
	movementComponent.behaviour.reset(new PlayerMovementBehaviour({"Idle"}, {"Walk"}));
	movementComponent.speed = 0.02f;

	const char *animNames[] = {"Attack", "Walk", "Idle", "Hit", "Die"};

	auto &animationListComponent = object.set<AnimationListComponent>();
	// animationListComponent.setAnimationEndCallback(std::bind(&AttackBehaviour::animationEndCallback, &cerberusAttackBehaviour, std::placeholders::_1, std::placeholders::_2));
	for (const char *animName : animNames) {
		Animation &anim = animationListComponent.add(bodyEntity, animName);
       	anim.speed = (anim.name != "Attack") ? 1.75f : 1.0f;
       	anim.speed = (anim.name != "Attack") ? ((anim.name == "Hit") ? 3.0f : 1.75f) : 1.0f;
	}

	animationListComponent.setLoop("Attack", false);
	animationListComponent.setLoop("Die", false);
	animationListComponent.setLoop("Hit", false);
	animationListComponent.setActiveAnimation(0, "Idle");

	return object;
}
