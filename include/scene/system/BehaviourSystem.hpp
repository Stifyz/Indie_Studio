/*
 * =====================================================================================
 *
 *       Filename:  BehaviourSystem.hpp
 *
 *    Description:
 *
 *        Created:  16/06/2017 08:39:17
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BEHAVIOURSYSTEM_HPP_
#define BEHAVIOURSYSTEM_HPP_

#include "SceneObject.hpp"

class BehaviourSystem {
	public:
		static void process(SceneObject &object);

		static void reset(SceneObject &object);
};

#endif // BEHAVIOURSYSTEM_HPP_
