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
#ifndef COINFACTORY_HPP_
#define COINFACTORY_HPP_

#include <OgreVector3.h>

#include "SceneObject.hpp"

class CoinFactory {
	public:
		static SceneObject create(const Ogre::Vector3 &pos);
};

#endif // COINFACTORY_HPP_
