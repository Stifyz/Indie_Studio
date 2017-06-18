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
#include "AudioPlayer.hpp"
#include "ChatState.hpp"
#include "GameOverState.hpp"
#include "GamePad.hpp"
#include "GameState.hpp"
#include "PauseMenuState.hpp"
#include "ResourceHandler.hpp"
#include "VictoryState.hpp"

#include "ArcherFactory.hpp"
#include "BerserkerFactory.hpp"
#include "CameraFactory.hpp"
#include "DiabolousFactory.hpp"
#include "DoorFactory.hpp"
#include "TorchFactory.hpp"
#include "KeyFactory.hpp"
#include "CerberusFactory.hpp"
#include "SinbadFactory.hpp"

GameState::GameState() : ApplicationState("Game"), m_map(ResourceHandler::getInstance().get<Map>("test_room")) {
	m_trayManager->showFrameStats(OgreBites::TL_BOTTOMLEFT);
	// m_trayManager->showLogo(OgreBites::TL_BOTTOMRIGHT);

	m_hud.init(m_trayManager.get());

	m_textBox.reset(new TextBox);
	m_textBox->init(m_trayManager->createTextBox(OgreBites::TL_BOTTOMRIGHT, "ChatBox_RO", "Chat", 200, 150));

	m_map.init(m_scene);

	m_sinbad = &m_scene.addObject(SinbadFactory::create());
	m_scene.addObject(ArcherFactory::create());
	// const SceneObject &berserker = m_scene.addObject(BerserkerFactory::create());
	m_camera = &m_scene.addObject(CameraFactory::create(*m_sinbad));

	// Mobs/spawners
	m_scene.addObject(CerberusFactory::create(Ogre::Vector3(50, 4, 50)));

	// Intelligent entities
	// m_scene.addObject(KeyFactory::create(Ogre::Vector3(20, 1.5, 30)));
	// m_scene.addObject(DoorFactory::create(Ogre::Vector3(30, 4, 20)));

	// Decoration
	m_scene.addObject(TorchFactory::create(Ogre::Vector3(16.5, 4, 40), Direction::Left));
	m_scene.addObject(TorchFactory::create(Ogre::Vector3(73.5, 4, 40), Direction::Right));
	m_scene.addObject(TorchFactory::create(Ogre::Vector3(40, 4, 72), Direction::Up));

	std::string &name = OgreData::getInstance().name();
	name = "Zimmer"; //mettre le nom de joueur vous identifiant dans le chat ;)

	// m_hud.addPlayer(archer);
	// m_hud.addPlayer(*m_sinbad);
	// m_hud.addPlayer(berserker);

	m_scene.addCollisionChecker([&] (SceneObject &object) {
		m_map.checkCollisions(object);
	});

	AudioPlayer::playMusic("game_theme");
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

	if (m_scene.objects().enemyCount() == 0) {
		hide();
		OgreData::getInstance().sceneManager()->destroyAllEntities();
		OgreData::getInstance().sceneManager()->destroyAllLights();
		OgreData::getInstance().renderWindow()->removeAllViewports();
		m_stateStack->pop();
		m_stateStack->push<VictoryState>();
		return;
	}

	if (m_scene.objects().playerCount() == 0) {
		hide();
		OgreData::getInstance().sceneManager()->destroyAllEntities();
		OgreData::getInstance().sceneManager()->destroyAllLights();
		OgreData::getInstance().renderWindow()->removeAllViewports();
		m_stateStack->pop();
		m_stateStack->push<GameOverState>();
		return;
	}

	m_scene.update();

	// m_hud.update();
	m_textBox->update();
}

void GameState::networkLoop(INetwork *network) {

}

