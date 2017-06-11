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
#include "AnimationListComponent.hpp"
#include "ArcherFactory.hpp"
#include "CollisionComponent.hpp"
#include "EntityListComponent.hpp"
#include "GamePadMovement.hpp"
#include "MovementComponent.hpp"
#include "SceneNodeComponent.hpp"

SceneObject ArcherFactory::create() {
	SceneObject object("Archer");
	object.set<MovementComponent>(new GamePadMovement);
	object.set<CollisionComponent>();

	auto &bodyNodeComponent = object.set<SceneNodeComponent>(Ogre::Vector3(30, ARCHER_HEIGHT, 30), Ogre::Vector3(0.3, 0.3, 0.3));
	auto &entityListComponent = object.set<EntityListComponent>(bodyNodeComponent.node);

	Ogre::Entity *bodyEntity = entityListComponent.addEntity("ArcherBody", "Archer.mesh", true);
	bodyEntity->setMaterialName("Archer");

	const char *animNames[] = {"my_animation"};

	auto &animationListComponent = object.set<AnimationListComponent>();
	for (const char *animName : animNames) {
		animationListComponent.add(bodyEntity, animName);
	}

	animationListComponent.setActiveAnimation(0, "my_animation");

	return object;
}

