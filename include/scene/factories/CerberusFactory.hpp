/*
 * =====================================================================================
 *
 *       Filename:  BerserkerFactory.hpp
 *
 *    Description:
 *
 *        Created:  05/06/2017 22:15:18
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef CERBERUSFACTORY_HPP_
#define CERBERUSFACTORY_HPP_

#include <OgreVector3.h>

#include "SceneObject.hpp"

#define CERBERUS_HEIGHT (5 / 1.8)

class CerberusFactory {
	public:
		static SceneObject create(const Ogre::Vector3 &pos);
};

#endif // CERBERUSFACTORY_HPP_
