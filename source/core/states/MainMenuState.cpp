/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* MainMenuState.cpp for project :
|*                                                          *|
|* Created: 2017-06-15 13:30
|*                                                          *|
\************************************************************/

#include <Ogre.h>

#include "AudioPlayer.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "OptionMenuState.hpp"

MainMenuState::MainMenuState() : ApplicationState("MainMenu") {
	m_background.init("MainMenu.png", "Menu");
	m_background.set();

	auto *sceneManager = OgreData::getInstance().sceneManager();
	m_camera = sceneManager->createCamera("Camera_Menu");
	m_camera->setAutoAspectRatio(true);
	m_camera->setNearClipDistance(0.1);
	m_camera->setFarClipDistance(1000);

	Ogre::RenderWindow *renderWindow = OgreData::getInstance().renderWindow();
	renderWindow->addViewport(m_camera);

	m_trayManager->createButton(OgreBites::TL_CENTER, "start", "Start Game", 200);
	// m_trayManager->createButton(OgreBites::TL_CENTER, "option", "Option", 200);
	m_trayManager->createButton(OgreBites::TL_CENTER, "quit", "Quit", 200);

	AudioPlayer::playMusic("title_screen");
}

void MainMenuState::update() {
	m_background.update();
}

void MainMenuState::buttonHit(OgreBites::Button *button) {
	AudioPlayer::playEffect("menu_select1");

	if (button->getName() == "start") {
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

