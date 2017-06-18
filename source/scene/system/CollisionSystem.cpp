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
	if(object1.has<CollisionComponent>() && object2.has<CollisionComponent>()) {
		auto &collisionComponent1 = object1.get<CollisionComponent>();
		auto &collisionComponent2 = object2.get<CollisionComponent>();

		for (const std::string &entityName1 : collisionComponent1.entitiesToCheck()) {
			for (const std::string &entityName2 : collisionComponent2.entitiesToCheck()) {
				CollisionInfo info = CollisionSystem::inCollision(object1, object2, entityName1, entityName2);

				object1.get<CollisionComponent>().collisionActions(object1, object2, info);
				object2.get<CollisionComponent>().collisionActions(object2, object1, info);
			}
		}
	}
}

CollisionInfo CollisionSystem::inCollision(SceneObject &object1, SceneObject &object2, const std::string &entityName1, const std::string &entityName2) {
	Ogre::Entity *entity1 = object1.get<EntityListComponent>().getEntity(object1.name() + entityName1);
	Ogre::Entity *entity2 = object2.get<EntityListComponent>().getEntity(object2.name() + entityName2);

	// FIXME: I should use spheres here but how to apply 'v'?
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

	return CollisionInfo{box1.intersects(box2), entityName1, entityName2};
}

