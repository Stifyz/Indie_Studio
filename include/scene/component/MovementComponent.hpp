/*
 * =====================================================================================
 *
 *       Filename:  MovementComponent.hpp
 *
 *    Description:
 *
 *        Created:  20/04/2017 23:18:45
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MOVEMENTCOMPONENT_HPP_
#define MOVEMENTCOMPONENT_HPP_

#include <functional>
#include <memory>

#include "Movement.hpp"
#include "OgreVector3.h"
// #include "Vector2.hpp"

class MovementComponent {
	public:
		MovementComponent(Movement *_movement) : movement(_movement) {}

		Ogre::Vector3 v{0, 0, 0};

		bool isMoving = false;
		bool isDirectionLocked = false;

		bool isBlocked = false;

		bool isGrowing = false;

		// float speed = 0.4f;
		float speed = 1.0f;

		std::unique_ptr<Movement> movement;

		std::function<void(SceneObject &)> behaviour;
};

#endif // MOVEMENTCOMPONENT_HPP_
