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

#include <memory>

#include "Behaviour.hpp"
#include "Movement.hpp"
#include "OgreVector3.h"

#include "VectorCom.hpp"

class MovementComponent {
	public:
		MovementComponent(Movement *_movement) : movement(_movement) {}

		Ogre::Vector3 v{0, 0, 0};

		bool isMoving = false;
		bool isDirectionLocked = false;

		bool isBlocked = false;

		float speed = 0.08f;

		std::unique_ptr<Movement> movement{nullptr};

		std::unique_ptr<Behaviour> behaviour{nullptr};
};

#endif // MOVEMENTCOMPONENT_HPP_
