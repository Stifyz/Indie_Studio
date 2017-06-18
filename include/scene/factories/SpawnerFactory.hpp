/*
 * =====================================================================================
 *
 *       Filename:  SpawnerFactory.hpp
 *
 *    Description:
 *
 *        Created:  17/06/2017 15:31:07
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SPAWNERFACTORY_HPP_
#define SPAWNERFACTORY_HPP_

#include <OgreVector3.h>

#include "SceneObject.hpp"

class SpawnerFactory {
	public:
		static SceneObject create(const Ogre::Vector3 &pos);
};

#endif // SPAWNERFACTORY_HPP_
