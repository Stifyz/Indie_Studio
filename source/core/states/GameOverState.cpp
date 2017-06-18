#include "AudioPlayer.hpp"
#include "GameState.hpp"
#include "GameOverState.hpp"
#include "OptionMenuState.hpp"

#include <Ogre.h>

GameOverState::GameOverState() : ApplicationState("GameOver") {
	AudioPlayer::playEffect("lose1");

	m_background.init("screen-gameover.png", "GameOver");
	m_background.set();

	auto *sceneManager = OgreData::getInstance().sceneManager();
	m_camera = sceneManager->createCamera("Camera_Menu");
	m_camera->setAutoAspectRatio(true);
	m_camera->setNearClipDistance(0.1);

	m_camera->setFarClipDistance(1000);

	Ogre::RenderWindow *renderWindow = OgreData::getInstance().renderWindow();
	renderWindow->addViewport(m_camera);

	// m_trayManager->createButton(OgreBites::TL_BOTTOM, "restart", "Restart", 200);
	// m_trayManager->createButton(OgreBites::TL_BOTTOM, "option", "Option", 200);
	m_trayManager->createButton(OgreBites::TL_BOTTOM, "quit", "Quit", 200);
}

void GameOverState::update() {
	m_background.update();
}

void GameOverState::buttonHit(OgreBites::Button *button) {
	AudioPlayer::playEffect("menu_select1");

	if (button->getName() == "continue") {
		auto *sceneManager = OgreData::getInstance().sceneManager();
		sceneManager->destroyAllCameras();

		Ogre::RenderWindow *renderWindow = OgreData::getInstance().renderWindow();
		renderWindow->removeAllViewports();
		m_stateStack->pop();
		m_stateStack->push<GameState>();
	}
	else if (button->getName() == "option") {
		hide();
		m_stateStack->push<OptionMenuState>(this);
	}
	else if (button->getName() == "quit") {
		m_stateStack->pop();
	}
}

