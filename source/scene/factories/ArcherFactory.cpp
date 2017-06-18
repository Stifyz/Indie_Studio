/*
 * =====================================================================================
 *
 *       Filename:  ArcherFactory.cpp
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
#include "ArcherFactory.hpp"
#include "ArcherShootBehaviour.hpp"
#include "BehaviourComponent.hpp"
#include "CollisionComponent.hpp"
#include "EntityListComponent.hpp"
#include "GamePadMovement.hpp"
#include "HealthComponent.hpp"
#include "LifetimeComponent.hpp"
#include "MovementComponent.hpp"
#include "PlayerMovementBehaviour.hpp"
#include "SceneObjectList.hpp"
#include "SceneNodeComponent.hpp"

SceneObject ArcherFactory::create() {
	SceneObject object("Archer", "Player");
	object.set<SceneObjectList>();
	object.set<CollisionComponent>();

	auto &healthComponent = object.set<HealthComponent>(300);
	object.set<LifetimeComponent>([&] (SceneObject &object) {
		return healthComponent.life() == 0;
	});

	auto &bodyNodeComponent = object.set<SceneNodeComponent>(Ogre::Vector3(30, ARCHER_HEIGHT, 30), Ogre::Vector3(0.3, 0.3, 0.3));
	auto &entityListComponent = object.set<EntityListComponent>(bodyNodeComponent.node);

	Ogre::Entity *bodyEntity = entityListComponent.addEntity("ArcherBody", "Archer.mesh", true);
	bodyEntity->setMaterialName("Archer");

	auto &behaviourComponent = object.set<BehaviourComponent>();
	auto &archerShootBehaviour = behaviourComponent.addBehaviour<ArcherShootBehaviour>("Shoot");

	auto &movementComponent = object.set<MovementComponent>(new GamePadMovement);
	movementComponent.behaviour.reset(new PlayerMovementBehaviour({"Idle"}, {"Walk"}));

	const char *animNames[] = {"Attack", "Walk", "Idle", "Hit", "Die"};

	auto &animationListComponent = object.set<AnimationListComponent>();
	animationListComponent.setAnimationEndCallback(std::bind(&AttackBehaviour::animationEndCallback, &archerShootBehaviour, std::placeholders::_1, std::placeholders::_2));
	for (const char *animName : animNames) {
		Animation &anim = animationListComponent.add(bodyEntity, animName);
		anim.speed = (anim.name != "Attack") ? 1.75f : 5.0f;
	}

	animationListComponent.setLoop("Attack", false);
	animationListComponent.setActiveAnimation(0, "Idle");

	return object;
}
