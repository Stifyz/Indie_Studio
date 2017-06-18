/*
 * =====================================================================================
 *
 *       Filename:  ArrowFactory.hpp
 *
 *    Description:
 *
 *        Created:  18/06/2017 02:48:51
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ARROWFACTORY_HPP_
#define ARROWFACTORY_HPP_

#include <OgreVector3.h>

#include "CollisionComponent.hpp"

class ArrowFactory {
	public:
		static SceneObject create(const Ogre::Vector3 &pos, const Ogre::Vector3 &v);

	private:
		static void arrowAction(SceneObject &arrow, SceneObject &object, const CollisionInfo &info);
};

#endif // ARROWFACTORY_HPP_
