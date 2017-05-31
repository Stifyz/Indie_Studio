/*
 * =====================================================================================
 *
 *       Filename:  AnimationSystem.hpp
 *
 *    Description:
 *
 *        Created:  29/05/2017 10:50:53
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ANIMATIONSYSTEM_HPP_
#define ANIMATIONSYSTEM_HPP_

#include "SceneObject.hpp"

class AnimationSystem {
	public:
		static void process(SceneObject &object);
};

#endif // ANIMATIONSYSTEM_HPP_
