/*
 * =====================================================================================
 *
 *       Filename:  Behaviour.hpp
 *
 *    Description:
 *
 *        Created:  15/06/2017 18:17:24
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BEHAVIOUR_HPP_
#define BEHAVIOUR_HPP_

#include "SceneObject.hpp"

class Behaviour {
	public:
		virtual void action(SceneObject &object) = 0;
};

#endif // BEHAVIOUR_HPP_
