/*
 * =====================================================================================
 *
 *       Filename:  CollisionSystem.cpp
 *
 *    Description:
 *
 *        Created:  20/04/2017 23:07:19
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "CollisionSystem.hpp"

#include "CollisionComponent.hpp"
#include "EntityListComponent.hpp"
#include "MovementComponent.hpp"

void CollisionSystem::checkCollision(SceneObject &object1, SceneObject &object2) {
	bool inCollision = CollisionSystem::inCollision(object1, object2);

	if(object1.has<CollisionComponent>()) {
		object1.get<CollisionComponent>().collisionActions(object1, object2, inCollision);
	}

	if(object2.has<CollisionComponent>()) {
		object2.get<CollisionComponent>().collisionActions(object2, object1, inCollision);
	}
}

bool CollisionSystem::inCollision(SceneObject &object1, SceneObject &object2) {
	Ogre::Entity *entity1 = object1.get<EntityListComponent>().getEntity(object1.name() + "Body");
	Ogre::Entity *entity2 = object2.get<EntityListComponent>().getEntity(object2.name() + "Body");

	Ogre::AxisAlignedBox box1 = entity1->getWorldBoundingBox();
	Ogre::AxisAlignedBox box2 = entity2->getWorldBoundingBox();

	if(object1.has<MovementComponent>()) {
		auto &v = object1.get<MovementComponent>().v;
		box1.getMinimum() += v;
		box1.getMaximum() += v;
	}

	if(object2.has<MovementComponent>()) {
		auto &v = object2.get<MovementComponent>().v;
		box2.getMinimum() += v;
		box2.getMaximum() += v;
	}

	if(box1.intersects(box2)) {
		return true;
	}

	return false;
}

