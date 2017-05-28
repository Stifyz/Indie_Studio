/*
 * =====================================================================================
 *
 *       Filename:  SinbadFactory.cpp
 *
 *    Description:
 *
 *        Created:  28/05/2017 13:22:44
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <Ogre.h>

#include "OgreData.hpp"
#include "SinbadFactory.hpp"

class SceneNodeComponent {
	public:
		SceneNodeComponent(const Ogre::Vector3 &pos, const Ogre::Vector3 &scale = Ogre::Vector3::ZERO) {
			Ogre::SceneManager *sceneManager = OgreData::getInstance().sceneManager();
			node = sceneManager->getRootSceneNode()->createChildSceneNode(pos);
			node->setScale(scale);
		}

		Ogre::SceneNode *node = nullptr;
};

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

class Animation {
	public:
		Animation(Ogre::Entity *entity, const char *animName) {
			state = entity->getAnimationState(animName);
			state->setLoop(true);
		}

		Ogre::AnimationState *state = nullptr;

		bool fadingIn = false;
		bool fadingOut = false;
};

class AnimationListComponent {
	public:
		void add(Ogre::Entity *entity, const char *animName) {
			m_animationList.emplace(animName, Animation{entity, animName});
		}

		void enableAnimation(const char *animName) {
			auto animIterator = m_animationList.find(animName);
			if (animIterator == m_animationList.end()) {
				animIterator->second.state->setEnabled(true);
			}
		}

		void disableAnimation(const char *animName) {
			auto animIterator = m_animationList.find(animName);
			if (animIterator == m_animationList.end()) {
				animIterator->second.state->setEnabled(false);
			}
		}

	private:
		std::map<const char *, Animation> m_animationList;
};

SceneObject SinbadFactory::create() {
	SceneObject object("Sinbad");

	auto &bodyNodeComponent = object.set<SceneNodeComponent>(Ogre::Vector3(20, CHAR_HEIGHT, 20), Ogre::Vector3(0.5, 0.5, 0.5));
	auto &entityListComponent = object.set<EntityListComponent>(bodyNodeComponent.node);

	Ogre::Entity *bodyEntity = entityListComponent.addEntity("SinbadBody_", "Sinbad.mesh", true);
	bodyEntity->getSkeleton()->setBlendMode(Ogre::ANIMBLEND_CUMULATIVE);

	entityListComponent.addEntity("SinbadSword1_", "Sword.mesh");
	entityListComponent.addEntity("SinbadSword2_", "Sword.mesh");
	entityListComponent.linkEntityToBone("SinbadSword1_", "SinbadBody_", "Sheath.L");
	entityListComponent.linkEntityToBone("SinbadSword2_", "SinbadBody_", "Sheath.R");

	const char *animNames[] = {
		"IdleBase", "IdleTop", "RunBase", "RunTop", "HandsClosed", "HandsRelaxed", "DrawSwords",
		"SliceVertical", "SliceHorizontal", "Dance", "JumpStart", "JumpLoop", "JumpEnd"
	};
	auto &animationListComponent = object.set<AnimationListComponent>();
	for (const char *animName : animNames) {
		animationListComponent.add(bodyEntity, animName);
	}
	animationListComponent.enableAnimation("HandsRelaxed");

	return object;
}

