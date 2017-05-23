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
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"

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
	if(object1.has<PositionComponent>() && object2.has<PositionComponent>()) {
		auto &position1 = object1.get<PositionComponent>();
		auto &position2 = object2.get<PositionComponent>();

		FloatRect rect1 = position1;
		FloatRect rect2 = position2;

		if(object1.has<MovementComponent>()) {
			rect1 += object1.get<MovementComponent>().v;
		}

		if(object2.has<MovementComponent>()) {
			rect2 += object2.get<MovementComponent>().v;
		}

		if(rect1.intersects(rect2)) {
			return true;
		}
	}

	return false;
}

