/*
 * =====================================================================================
 *
 *       Filename:  SpawnerSystem.hpp
 *
 *    Description:
 *
 *        Created:  20/06/2017 14:22:51
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SPAWNERSYSTEM_HPP_
#define SPAWNERSYSTEM_HPP_

#include "SceneObjectList.hpp"

class SpawnerSystem {
	public:
		static void process(SceneObjectList &objectList);
};

#endif // SPAWNERSYSTEM_HPP_
