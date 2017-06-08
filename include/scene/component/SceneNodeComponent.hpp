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
#ifndef SCENENODECOMPONENT_HPP_
#define SCENENODECOMPONENT_HPP_

#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreVector3.h>

#include "OgreData.hpp"

class SceneNodeComponent {
	public:
		SceneNodeComponent(Ogre::SceneNode *_node) {
			Ogre::SceneManager *sceneManager = OgreData::getInstance().sceneManager();
			node = sceneManager->getRootSceneNode()->createChildSceneNode();
			// node = _node->createChildSceneNode();
			node->setAutoTracking(true, _node);
		}

		SceneNodeComponent(const Ogre::Vector3 &pos, const Ogre::Vector3 &scale = Ogre::Vector3::UNIT_SCALE) {
			Ogre::SceneManager *sceneManager = OgreData::getInstance().sceneManager();
			node = sceneManager->getRootSceneNode()->createChildSceneNode(pos);
			node->setScale(scale);
		}

		Ogre::SceneNode *node = nullptr;
};

#endif // SCENENODECOMPONENT_HPP_
