/*
 * =====================================================================================
 *
 *       Filename:  DoorFactory.hpp
 *
 *    Description:
 *
 *        Created:  17/06/2017 15:31:07
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef DOORFACTORY_HPP_
#define DOORFACTORY_HPP_

#include <OgreVector3.h>

#include "SceneObject.hpp"

class DoorFactory {
	public:
		static SceneObject create(const Ogre::Vector3 &pos);
};

#endif // DOORFACTORY_HPP_
