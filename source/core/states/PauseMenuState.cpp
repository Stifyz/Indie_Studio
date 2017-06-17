/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* PauseMenuState.cpp for project :
|*                                                          *|
|* Created: 2017-06-15 11:17
|*                                                          *|
\************************************************************/

#include "OgreData.hpp"
#include "PauseMenuState.hpp"

PauseMenuState::PauseMenuState() {
	OgreBites::TrayManager *trayManager = OgreData::getInstance().trayManager();
	trayManager->setListener(this);

	trayManager->createButton(OgreBites::TL_CENTER, "start", "Pause Game", 200);
	trayManager->createButton(OgreBites::TL_CENTER, "quit", "Quit", 200);
}

void PauseMenuState::update() {
}

void PauseMenuState::buttonHit(OgreBites::Button *button) {
	if (button->getName() == "start") {
		OgreBites::TrayManager *trayManager = OgreData::getInstance().trayManager();
		trayManager->destroyAllWidgetsInTray(OgreBites::TrayLocation::TL_CENTER);
		m_stateStack->pop();
	}
	else if (button->getName() == "quit") {
		OgreData::getInstance().root()->queueEndRendering();
	}
}

