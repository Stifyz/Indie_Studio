/*
 * =====================================================================================
 *
 *       Filename:  MovementSystem.cpp
 *
 *    Description:
 *
 *        Created:  20/04/2017 23:05:27
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Debug.hpp"
#include "MovementSystem.hpp"

#include "CollisionComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"

void MovementSystem::process(SceneObject &object) {
	if(object.has<MovementComponent>()) {
		auto &movement = object.get<MovementComponent>();

		if (movement.movement)
			movement.movement->process(object);
		movement.isBlocked = false;
	}

	if(object.has<CollisionComponent>()) {
		object.get<CollisionComponent>().checkCollisions(object);
	}

	if(object.has<PositionComponent>() && object.has<MovementComponent>()) {
		auto &position = object.get<PositionComponent>();
		auto &movement = object.get<MovementComponent>();

		movement.isMoving = (movement.v.x || movement.v.y) ? true : false;

		if (movement.behaviour)
			movement.behaviour(object);
		else {
			position.scale(movement.v * movement.speed);

			movement.v = 0;
		}
	}
}

