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

#include "GamePad.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "OgreData.hpp"
#include "ResourceHandler.hpp"

#include "ArcherFactory.hpp"
#include "BerserkerFactory.hpp"
#include "DiabolousFactory.hpp"
#include "BossFactory.hpp"
#include "CameraFactory.hpp"
#include "HeartFactory.hpp"
#include "SinbadFactory.hpp"

GameState::GameState() : m_room(ResourceHandler::getInstance().get<Room>("test_room")) {
	m_room.init();

	m_sinbad = &m_scene.addObject(SinbadFactory::create());
	m_scene.addObject(ArcherFactory::create());
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
	if (GamePad::isKeyPressed(GameKey::Start)) {
		m_stateStack->push<MainMenuState>();
		return;
	}

	m_scene.update();
}

