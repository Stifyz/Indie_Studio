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
#ifndef TORCHFACTORY_HPP_
#define TORCHFACTORY_HPP_

#include <OgreVector3.h>

#include "Direction.hpp"
#include "SceneObject.hpp"

class TorchFactory {
	public:
  static SceneObject create(const Ogre::Vector3 &pos, const Direction);
};

#endif // TORCHFACTORY_HPP_
