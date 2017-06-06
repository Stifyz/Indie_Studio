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
#include "SceneNodeComponent.hpp"

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

	if(object.has<MovementComponent>()) {
		auto &movement = object.get<MovementComponent>();
		movement.isMoving = (movement.v.x || movement.v.z) ? true : false;

		if (movement.behaviour)
			movement.behaviour(object);

		Ogre::SceneNode *node = object.get<SceneNodeComponent>().node;
		node->setPosition(node->getPosition() + movement.v * movement.speed);

		movement.v = 0;
	}
}

