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
#include "CameraFactory.hpp"
#include "GameState.hpp"
#include "OgreData.hpp"
#include "ResourceHandler.hpp"
#include "SinbadFactory.hpp"

GameState::GameState() : m_room(ResourceHandler::getInstance().get<Room>("tuto_room")) {
	m_room.init();

	SceneObject &sinbad = m_scene.addObject(SinbadFactory::create());
	m_scene.addObject(ArcherFactory::create());
	m_scene.addObject(CameraFactory::create(sinbad));

	m_scene.addCollisionChecker([&] (SceneObject &object) {
		m_room.checkCollisions(object);
	});
}

void GameState::update() {
	m_scene.update();
}

