/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* MainMenuState.cpp for project :
|*                                                          *|
|* Created: 2017-06-15 13:30
|*                                                          *|
\************************************************************/

#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "OptionMenuState.hpp"

#include <Ogre.h>

MainMenuState::MainMenuState() : ApplicationState("MainMenu") {
	m_background.init("backgroundmenu3.tga", "Menu");
	m_background.set("backgroundmenu3.tga", "Menu");

	auto *sceneManager = OgreData::getInstance().sceneManager();
	m_camera = sceneManager->createCamera("Camera_Menu");
	m_camera->setAutoAspectRatio(true);
	m_camera->setNearClipDistance(0.1);
	m_camera->setFarClipDistance(1000);

	Ogre::RenderWindow *renderWindow = OgreData::getInstance().renderWindow();
	renderWindow->addViewport(m_camera);

	m_trayManager->createButton(OgreBites::TL_CENTER, "start", "Start Game", 200);
	m_trayManager->createButton(OgreBites::TL_CENTER, "option", "Option", 200);
	m_trayManager->createButton(OgreBites::TL_CENTER, "quit", "Quit", 200);
}

void MainMenuState::update() {
	m_background.update();
}

void MainMenuState::buttonHit(OgreBites::Button *button) {
	if (button->getName() == "start") {
		// m_trayManager->destroyAllWidgetsInTray(OgreBites::TrayLocation::TL_CENTER);
		auto *sceneManager = OgreData::getInstance().sceneManager();
		Ogre::MaterialManager::getSingleton().remove("backgroundmenu3.tga_Main");
		sceneManager->destroyAllCameras();
		// m_trayManager.reset(nullptr);
		// sceneManager->destroyAllMovableObjects();
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

