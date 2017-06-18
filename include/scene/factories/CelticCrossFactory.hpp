/*
 * =====================================================================================
 *
 *       Filename:  HeartFactory.hpp
 *
 *    Description:
 *
 *        Created:  17/06/2017 15:31:07
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef CELTICCROSSFACTORY_HPP_
#define CELTICCROSSFACTORY_HPP_

#include <OgreVector3.h>

#include "SceneObject.hpp"

class CelticCrossFactory {
	public:
		static SceneObject create(const Ogre::Vector3 &pos);
};

#endif // CELTICCROSSFACTORY_HPP_
