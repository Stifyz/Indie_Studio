/*
 * =====================================================================================
 *
 *       Filename:  MainMenuState.cpp
 *
 *    Description:
 *
 *        Created:  10/06/2017 14:28:47
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "MainMenuState.hpp"
#include "OgreData.hpp"

MainMenuState::MainMenuState(OgreBites::TrayManager *trayManager) : m_trayManager(trayManager) {
	m_trayManager->setListener(this);

	m_trayManager->createButton(OgreBites::TL_CENTER, "start", "Start Game", 200);
	m_trayManager->createButton(OgreBites::TL_CENTER, "quit", "Quit", 200);
}

void MainMenuState::update() {
}

void MainMenuState::buttonHit(OgreBites::Button *button) {
	if (button->getName() == "start") {
		m_trayManager->destroyAllWidgetsInTray(OgreBites::TrayLocation::TL_CENTER);
		m_stateStack->pop();
	}
	else if (button->getName() == "quit") {
		OgreData::getInstance().root()->queueEndRendering();
	}
}

