<<<<<<< HEAD
/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* SceneNodeComponent.hpp for project :
|*                                                          *|
|* Created: 2017-06-05 19:00
|*                                                          *|
\************************************************************/

=======
/*
 * =====================================================================================
 *
 *       Filename:  SceneNodeComponent.hpp
 *
 *    Description:
 *
 *        Created:  05/06/2017 22:17:36
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
>>>>>>> a5023387dd89e87227e8101de112ce1ed92acda4
#ifndef SCENENODECOMPONENT_HPP_
#define SCENENODECOMPONENT_HPP_

#include <OgreVector3.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

#include "OgreData.hpp"

class SceneNodeComponent {
	public:
<<<<<<< HEAD
		SceneNodeComponent(const Ogre::Vector3 &pos, const Ogre::Vector3 &scale = Ogre::Vector3::ZERO) {
=======
		SceneNodeComponent(const Ogre::Vector3 &pos, const Ogre::Vector3 &scale = Ogre::Vector3::UNIT_SCALE) {
>>>>>>> a5023387dd89e87227e8101de112ce1ed92acda4
			Ogre::SceneManager *sceneManager = OgreData::getInstance().sceneManager();
			node = sceneManager->getRootSceneNode()->createChildSceneNode(pos);
			node->setScale(scale);
		}

		Ogre::SceneNode *node = nullptr;
};

<<<<<<< HEAD
#endif // !SCENENODECOMPONENT_HPP_
=======
#endif // SCENENODECOMPONENT_HPP_
>>>>>>> a5023387dd89e87227e8101de112ce1ed92acda4
