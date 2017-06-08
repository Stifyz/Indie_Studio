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

#include "ArcherFactory.hpp"
#include "GameState.hpp"
#include "OgreData.hpp"
#include "ResourceHandler.hpp"
#include "SinbadFactory.hpp"

GameState::GameState() : m_room(ResourceHandler::getInstance().get<Room>("tuto_room")) {
	Ogre::RenderWindow *renderWindow = OgreData::getInstance().renderWindow();
	Ogre::SceneManager *sceneManager = OgreData::getInstance().sceneManager();

	OgreData::getInstance().app()->addInputListener(this);
	OgreData::getInstance().root()->addFrameListener(this);

	Ogre::Camera* camera = sceneManager->createCamera("myCam");
	camera->setAutoAspectRatio(true);

	Ogre::SceneNode* cameraNode = sceneManager->getRootSceneNode()->createChildSceneNode();
	cameraNode->setPosition(0, 0, 15);
	cameraNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);
	cameraNode->attachObject(camera);

	renderWindow->addViewport(camera);

	m_room.init(sceneManager);
	m_chara.init(camera);

	m_scene.addObject(ArcherFactory::create());
	m_scene.addObject(SinbadFactory::create());

	m_scene.addCollisionChecker([&] (SceneObject &object) {
		m_room.checkCollisions(object);
	});
}

void GameState::update() {
	m_scene.update();
}

bool GameState::frameRenderingQueued(const Ogre::FrameEvent &evt) {
	m_chara.addTime(evt.timeSinceLastFrame);
	return true;
}

bool GameState::keyPressed(const OgreBites::KeyboardEvent &evt) {
	m_chara.injectKeyDown(evt);
	return true;
}

bool GameState::keyReleased(const OgreBites::KeyboardEvent &evt) {
	m_chara.injectKeyUp(evt);
	return true;
}

bool GameState::mouseMoved(const OgreBites::MouseMotionEvent &evt) {
	m_chara.injectMouseMove(evt);
	return true;
}

bool GameState::mouseWheelRolled(const OgreBites::MouseWheelEvent &evt) {
	m_chara.injectMouseWheel(evt);
	return true;
}

bool GameState::mousePressed(const OgreBites::MouseButtonEvent &evt) {
	m_chara.injectMouseDown(evt);
	return true;
}

