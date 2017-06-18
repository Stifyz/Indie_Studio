/*
 * =====================================================================================
 *
 *       Filename:  LifeBarBehaviour.hpp
 *
 *    Description:
 *
 *        Created:  18/06/2017 21:15:15
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LIFEBARBEHAVIOUR_HPP_
#define LIFEBARBEHAVIOUR_HPP_

#include <OgreBillboard.h>
#include <OgreSceneNode.h>
#include <OgreVector3.h>

#include "Behaviour.hpp"

class LifeBarBehaviour : public Behaviour {
	public:
		LifeBarBehaviour(Ogre::SceneNode *root, const Ogre::Vector3 &pos);

		void update(SceneObject &object);

	private:
		static const unsigned int s_size = 4;

		Ogre::Billboard *m_billboard = nullptr;
};


#endif // LIFEBARBEHAVIOUR_HPP_
