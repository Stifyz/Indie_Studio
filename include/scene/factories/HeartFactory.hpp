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
#ifndef HEARTFACTORY_HPP_
#define HEARTFACTORY_HPP_

#include <OgreVector3.h>

#include "CollisionComponent.hpp"

class HeartFactory {
	public:
		static SceneObject create(const Ogre::Vector3 &pos);

	private:
		static void heartAction(SceneObject &heart, SceneObject &object, const CollisionInfo &info);
};

#endif // HEARTFACTORY_HPP_
