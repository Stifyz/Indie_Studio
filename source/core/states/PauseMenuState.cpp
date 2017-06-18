/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* PauseMenuState.cpp for project :
|*                                                          *|
|* Created: 2017-06-15 11:17
|*                                                          *|
\************************************************************/

#include "PauseMenuState.hpp"

PauseMenuState::PauseMenuState(ApplicationState *parent) : ApplicationState("PauseMenu", parent) {
	OgreBites::TrayManager *trayManager = OgreData::getInstance().trayManager();
	trayManager->setListener(this);

	trayManager->createButton(OgreBites::TL_CENTER, "start", "Pause Game", 200);
	trayManager->createButton(OgreBites::TL_CENTER, "quit", "Quit", 200);
}

void PauseMenuState::update() {
}

void PauseMenuState::buttonHit(OgreBites::Button *button) {
	if (button->getName() == "start") {
		// m_trayManager->destroyAllWidgetsInTray(OgreBites::TrayLocation::TL_CENTER);
		m_stateStack->pop();
		m_parent->show();
	}
	else if (button->getName() == "quit") {
		// OgreData::getInstance().root()->queueEndRendering();
		m_stateStack->pop();
		m_stateStack->pop();
	}
}
