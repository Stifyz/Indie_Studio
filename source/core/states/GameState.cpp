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
// #include <Ogre.h>

#include "ChatState.hpp"
#include "GamePad.hpp"
#include "GameState.hpp"
#include "PauseMenuState.hpp"
#include "ResourceHandler.hpp"

#include "ArcherFactory.hpp"
#include "BerserkerFactory.hpp"
#include "DiabolousFactory.hpp"
#include "BossFactory.hpp"
#include "CameraFactory.hpp"
#include "HeartFactory.hpp"
#include "SinbadFactory.hpp"

GameState::GameState() : ApplicationState("Game"), m_room(ResourceHandler::getInstance().get<Room>("test_room")) {
	m_trayManager->showFrameStats(OgreBites::TL_BOTTOMLEFT);
	// m_trayManager->showLogo(OgreBites::TL_BOTTOMRIGHT);

	m_textBox.reset(new TextBox);
	m_textBox->init(m_trayManager->createTextBox(OgreBites::TL_BOTTOMRIGHT, "ChatBox_RO", "Chat", 200, 150));

	m_room.init();

	m_sinbad = &m_scene.addObject(SinbadFactory::create());
	m_scene.addObject(ArcherFactory::create(30, 30));
	m_camera = &m_scene.addObject(CameraFactory::create(*m_sinbad));

	m_scene.addObject(HeartFactory::create(Ogre::Vector3(30, 1.5, 30)));

	m_scene.addObject(BerserkerFactory::create());
	m_scene.addObject(DiabolousFactory::create());
	m_scene.addObject(BossFactory::create());

	m_scene.addCollisionChecker([&] (SceneObject &object) {
		m_room.checkCollisions(object);
	});
}

void GameState::update() {
	if (GamePad::isKeyPressedOnce(GameKey::Start)) {
		hide();
		m_stateStack->push<PauseMenuState>(this);
		return;
	}
	if (GamePad::isKeyPressedOnce(GameKey::Select)) {
		hide();
		m_stateStack->push<ChatState>(this);
		return;
	}
	m_scene.update();
	m_textBox->update();
}
