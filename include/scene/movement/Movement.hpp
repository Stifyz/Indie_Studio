/*
 * =====================================================================================
 *
 *       Filename:  Movement.hpp
 *
 *    Description:
 *
 *        Created:  20/04/2017 23:20:34
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MOVEMENT_HPP_
#define MOVEMENT_HPP_

#include "SceneObject.hpp"

#include <OgreVector3.h>
#include <OgreQuaternion.h>

class Movement {
	public:
		virtual ~Movement() = default;

		bool isFinished() const { return m_isFinished; }

		virtual void process(SceneObject &object) = 0;

	protected:
		bool m_isFinished = false;

		void turnToUp(Ogre::Quaternion &orientation);
		void turnToDown(Ogre::Quaternion &orientation);
		void turnToLeft(Ogre::Quaternion &orientation);
		void turnToRight(Ogre::Quaternion &orientation);

		void turnLeft(Ogre::Quaternion &orientation, float degree = 90);
		void turnRight(Ogre::Quaternion &orientation, float degree = 90);

		void goForward(Ogre::Quaternion orientation, Ogre::Vector3 position);
		void goBackward(Ogre::Quaternion orientation, Ogre::Vector3 position);

		void goUp(Ogre::Vector3 &position, float distance = 1);
		void goDown(Ogre::Vector3 &position, float distance = 1);
		void goLeft(Ogre::Vector3 &position, float distance = 1);
		void goRight(Ogre::Vector3 &position, float distance = 1);
};

#endif // MOVEMENT_HPP_
