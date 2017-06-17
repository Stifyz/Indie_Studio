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
#include "DiabolousFactory.hpp"
#include "DiabolousAttackBehaviour.hpp"
#include "BehaviourComponent.hpp"
#include "CollisionComponent.hpp"
#include "EntityListComponent.hpp"
#include "GamePadMovement.hpp"
#include "MovementComponent.hpp"
#include "PlayerMovementBehaviour.hpp"
#include "SceneNodeComponent.hpp"

SceneObject DiabolousFactory::create() {
	SceneObject object("Diabolous");
	object.set<CollisionComponent>();

	auto &bodyNodeComponent = object.set<SceneNodeComponent>(Ogre::Vector3(40, DIABOLOUS_HEIGHT, 30), Ogre::Vector3(0.3, 0.3, 0.3));
	auto &entityListComponent = object.set<EntityListComponent>(bodyNodeComponent.node);

	Ogre::Entity *bodyEntity = entityListComponent.addEntity("DiabolousBody", "Diabolous.mesh", true);
	bodyEntity->setMaterialName("Diabolous");

	auto &behaviourComponent = object.set<BehaviourComponent>();
       	auto &diabolousAttackBehaviour = behaviourComponent.addBehaviour<DiabolousAttackBehaviour>("Fight");

	auto &movementComponent = object.set<MovementComponent>(new GamePadMovement);
	movementComponent.behaviour.reset(new PlayerMovementBehaviour({"Wings"}, {"Walk"}));

	const char *animNames[] = {"Attack", "Walk", "Wings", "Hit", "Die"};

	auto &animationListComponent = object.set<AnimationListComponent>();
       	animationListComponent.setAnimationEndCallback(std::bind(&DiabolousAttackBehaviour::animationEndCallback, &diabolousAttackBehaviour, std::placeholders::_1, std::placeholders::_2));
	for (const char *animName : animNames) {
		Animation &anim = animationListComponent.add(bodyEntity, animName);
       	anim.speed = (anim.name != "Attack") ? 1.75f : 1.0f;
	}

	animationListComponent.setLoop("Attack", false);
	animationListComponent.setActiveAnimation(0, "Wings");

	return object;
}
