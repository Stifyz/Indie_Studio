/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* SceneNodeComponent.hpp for project :
|*                                                          *|
|* Created: 2017-06-05 19:00
|*                                                          *|
\************************************************************/

#ifndef SCENENODECOMPONENT_HPP_
#define SCENENODECOMPONENT_HPP_

#include <OgreVector3.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

#include "OgreData.hpp"

class SceneNodeComponent {
	public:
		SceneNodeComponent(const Ogre::Vector3 &pos, const Ogre::Vector3 &scale = Ogre::Vector3::ZERO) {
			Ogre::SceneManager *sceneManager = OgreData::getInstance().sceneManager();
			node = sceneManager->getRootSceneNode()->createChildSceneNode(pos);
			node->setScale(scale);
		}

		Ogre::SceneNode *node = nullptr;
};

#endif // !SCENENODECOMPONENT_HPP_
