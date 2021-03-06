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
#ifndef ENTITYLISTCOMPONENT_HPP_
#define ENTITYLISTCOMPONENT_HPP_

#include <map>

#include <OgreEntity.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

#include "Exception.hpp"
#include "OgreData.hpp"

class EntityListComponent {
	public:
		EntityListComponent(Ogre::SceneNode *rootNode) {
			m_rootNode = rootNode;
		}

		Ogre::Entity *addEntity(const std::string &name, const char *meshFilename, const bool attachObjectToRoot = false) {
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

		Ogre::Entity *getEntity(const std::string &name) {
			auto entity = m_entityList.find(name);
			if (entity == m_entityList.end())
				throw EXCEPTION("Entity not found:", name);
			return entity->second;
		}

	private:
		std::map<std::string, Ogre::Entity *> m_entityList;

		Ogre::SceneNode *m_rootNode = nullptr;
};

#endif // ENTITYLISTCOMPONENT_HPP_
