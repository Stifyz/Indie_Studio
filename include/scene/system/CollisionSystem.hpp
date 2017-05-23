/*
 * =====================================================================================
 *
 *       Filename:  CollisionSystem.hpp
 *
 *    Description:
 *
 *        Created:  20/04/2017 23:07:05
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COLLISIONSYSTEM_HPP_
#define COLLISIONSYSTEM_HPP_

#include "SceneObject.hpp"

class CollisionSystem {
	public:
		static void checkCollision(SceneObject &object1, SceneObject &object2);

		static bool inCollision(SceneObject &object1, SceneObject &object2);
};

#endif // COLLISIONSYSTEM_HPP_
