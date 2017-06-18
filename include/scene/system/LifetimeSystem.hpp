/*
 * =====================================================================================
 *
 *       Filename:  LifetimeSystem.hpp
 *
 *    Description:
 *
 *        Created:  18/06/2017 16:54:08
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LIFETIMESYSTEM_HPP_
#define LIFETIMESYSTEM_HPP_

#include "SceneObjectList.hpp"

class LifetimeSystem {
	public:
		static void process(SceneObjectList &objects);
};

#endif // LIFETIMESYSTEM_HPP_
