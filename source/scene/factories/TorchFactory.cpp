/*
 * =====================================================================================
 *
 *       Filename:  HeartFactory.cpp
 *
 *    Description:
 *
 *        Created:  17/06/2017 15:39:03
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "BehaviourComponent.hpp"
#include "CollisionComponent.hpp"
#include "EasyBehaviour.hpp"
#include "EntityListComponent.hpp"
#include "TorchFactory.hpp"
#include "SceneNodeComponent.hpp"
#include "SceneObject.hpp"

static unsigned long int torchCount = 0;

SceneObject TorchFactory::create(const Ogre::Vector3 &pos, const Direction dir) {
	SceneObject object{"Torch" + std::to_string(torchCount++)};
	object.set<CollisionComponent>();

	auto &bodyNodeComponent = object.set<SceneNodeComponent>(pos, Ogre::Vector3(1.5, 1.5, 1.5));
	switch (dir) {
		case Direction::Right: bodyNodeComponent.node->yaw(Ogre::Degree(180)); break;
		case Direction::Down : bodyNodeComponent.node->yaw(Ogre::Degree(270)); break;
		case Direction::Up   : bodyNodeComponent.node->yaw(Ogre::Degree(90));  break;
		case Direction::Left : bodyNodeComponent.node->yaw(Ogre::Degree(0));   break;
	}

	auto &entityListComponent = object.set<EntityListComponent>(bodyNodeComponent.node);
	Ogre::Entity *bodyEntity = entityListComponent.addEntity(object.name() + "Body", "Torch.mesh", true);

	Ogre::SceneManager *sceneManager = OgreData::getInstance().sceneManager();
	Ogre::Light* light = sceneManager->createLight(object.name() + "TorchLight");
	light->setType(Ogre::Light::LT_POINT);
	light->setPosition(bodyNodeComponent.root->getPosition() + bodyEntity->getWorldBoundingBox().getMinimum().midPoint(bodyEntity->getWorldBoundingBox().getMaximum()));
	light->setSpecularColour(Ogre::ColourValue::Red);
	light->setDiffuseColour(1, 0.45, 0.45);
	light->setAttenuation(2, 0, 0.1, 0);

	return object;
}

