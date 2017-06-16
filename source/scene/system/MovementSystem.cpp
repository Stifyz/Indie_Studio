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
	Ogre::SceneNode *root = object.get<SceneNodeComponent>().root;
	Ogre::SceneNode *node = object.get<SceneNodeComponent>().node;

	if(object.has<MovementComponent>()) {
		auto &movement = object.get<MovementComponent>();

		if (movement.movement)
			movement.movement->process(object);
		movement.isBlocked = false;

		if (movement.v.x || movement.v.z) {
			node->resetOrientation();
			node->setDirection(-movement.v);
		}
	}

	if(object.has<CollisionComponent>()) {
		object.get<CollisionComponent>().checkCollisions(object);
	}

	if(object.has<MovementComponent>()) {
		auto &movement = object.get<MovementComponent>();
		movement.isMoving = (movement.v.x || movement.v.z) ? true : false;

		if (movement.behaviour)
			movement.behaviour->action(object);

		root->setPosition(root->getPosition() + movement.v * movement.speed);

		movement.v = 0;
	}
}

