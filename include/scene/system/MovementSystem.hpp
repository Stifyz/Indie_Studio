/*
 * =====================================================================================
 *
 *       Filename:  MovementSystem.hpp
 *
 *    Description:
 *
 *        Created:  20/04/2017 23:05:02
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MOVEMENTSYSTEM_HPP_
#define MOVEMENTSYSTEM_HPP_

#include "SceneObject.hpp"

class MovementSystem {
	public:
		static void process(SceneObject &object);
};

#endif // MOVEMENTSYSTEM_HPP_
