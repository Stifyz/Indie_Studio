/*
 * =====================================================================================
 *
 *       Filename:  CameraFactory.cpp
 *
 *    Description:
 *
 *        Created:  08/06/2017 20:52:16
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <OgreCamera.h>

#include "CameraFactory.hpp"
#include "OgreData.hpp"
#include "SceneNodeComponent.hpp"

SceneObject CameraFactory::create(SceneObject &objectToWatch) {
	SceneObject object("Camera_" + objectToWatch.name());

	auto *sceneManager = OgreData::getInstance().sceneManager();
	Ogre::Camera *camera = sceneManager->createCamera(object.name());
	objectToWatch.set<Ogre::Camera *>(camera);
	camera->setAutoAspectRatio(true);
	camera->setNearClipDistance(0.1);
	camera->setFarClipDistance(1000);

	Ogre::RenderWindow *renderWindow = OgreData::getInstance().renderWindow();
	renderWindow->addViewport(camera);

	auto &sceneNodeComponentToWatch = objectToWatch.get<SceneNodeComponent>();
	auto &sceneNodeComponent = object.set<SceneNodeComponent>(sceneNodeComponentToWatch.root, sceneNodeComponentToWatch.node);
	sceneNodeComponent.node->attachObject(camera);
	// sceneNodeComponent.node->setInheritOrientation(false);
	// sceneNodeComponent.node->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_LOCAL);
	sceneNodeComponent.node->setPosition(0, 75, 50);
	sceneNodeComponent.node->setFixedYawAxis(true);

	return object;
}

