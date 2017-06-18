/*
 * =====================================================================================
 *
 *       Filename:  RadarSystem.hpp
 *
 *    Description:
 *
 *        Created:  19/06/2017 15:44:45
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef RADARSYSTEM_HPP_
#define RADARSYSTEM_HPP_

#include "SceneObjectList.hpp"

class RadarSystem {
	public:
		static void process(SceneObjectList &objectList);
};

#endif // RADARSYSTEM_HPP_
