<<<<<<< HEAD
/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* EntityListComponent.hpp for project :
|*                                                          *|
|* Created: 2017-06-05 18:54
|*                                                          *|
\************************************************************/

=======
/*
 * =====================================================================================
 *
 *       Filename:  EntityListComponent.hpp
 *
 *    Description:
 *
 *        Created:  05/06/2017 22:18:06
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
>>>>>>> a5023387dd89e87227e8101de112ce1ed92acda4
#ifndef ENTITYLISTCOMPONENT_HPP_
#define ENTITYLISTCOMPONENT_HPP_

#include <OgreEntity.h>
<<<<<<< HEAD
#include <OgreSceneNode.h>
#include <map>
=======
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
>>>>>>> a5023387dd89e87227e8101de112ce1ed92acda4

#include "OgreData.hpp"

class EntityListComponent {
	public:
		EntityListComponent(Ogre::SceneNode *rootNode) {
			m_rootNode = rootNode;
		}

		Ogre::Entity *addEntity(const char *name, const char *meshFilename, bool attachObjectToRoot = false) {
			Ogre::SceneManager *sceneManager = OgreData::getInstance().sceneManager();
			Ogre::Entity *entity = sceneManager->createEntity(name, meshFilename);
			if (attachObjectToRoot)
				m_rootNode->attachObject(entity);
			m_entityList.emplace(name, entity);
			return entity;
		}

		void linkEntityToBone(const char *linkedEntityName, const char *parentEntityName, const char *boneName) {
			auto parentEntity = m_entityList.find(parentEntityName);
			if (parentEntity == m_entityList.end())
				throw EXCEPTION("Failed to load entity:", parentEntityName);

			auto linkedEntity = m_entityList.find(linkedEntityName);
			if (linkedEntity == m_entityList.end())
				throw EXCEPTION("Failed to load entity:", linkedEntityName);

			parentEntity->second->attachObjectToBone(boneName, linkedEntity->second);
		}

	private:
		std::map<const char *, Ogre::Entity *> m_entityList;

		Ogre::SceneNode *m_rootNode = nullptr;
};

<<<<<<< HEAD
#endif // !ENTITYLISTCOMPONENT_HPP_
=======
#endif // ENTITYLISTCOMPONENT_HPP_
>>>>>>> a5023387dd89e87227e8101de112ce1ed92acda4
