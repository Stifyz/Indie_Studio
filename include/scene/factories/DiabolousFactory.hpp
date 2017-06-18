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
#ifndef DIABOLOUSFACTORY_HPP_
#define DIABOLOUSFACTORY_HPP_

#include <OgreVector3.h>

#include "SceneObject.hpp"

#define DIABOLOUS_HEIGHT (5 / 1.8)

class DiabolousFactory {
	public:
		static SceneObject create(const Ogre::Vector3 &pos);
};

#endif // DIABOLOUSFACTORY_HPP_
