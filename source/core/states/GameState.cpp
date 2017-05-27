/*
 * =====================================================================================
 *
 *       Filename:  GameState.cpp
 *
 *    Description:
 *
 *        Created:  25/05/2017 00:29:12
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <Ogre.h>

#include "GameState.hpp"

void GameState::init() {
	Ogre::SceneNode* cameraNode = m_sceneManager->getRootSceneNode()->createChildSceneNode();
	cameraNode->setPosition(0, 0, 15);
	cameraNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

	Ogre::Camera* camera = m_sceneManager->createCamera("myCam");
	camera->setAutoAspectRatio(true);
	cameraNode->attachObject(camera);

	Ogre::Root::getSingletonPtr()->getAutoCreatedWindow()->addViewport(camera);

	m_room.init(m_sceneManager);
	m_chara.init(camera);
}

void GameState::update() {
	m_scene.update();
}

