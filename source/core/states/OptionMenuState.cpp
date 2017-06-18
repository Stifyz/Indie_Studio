/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* OptionMenuState.cpp for project :
|*                                                          *|
|* Created: 2017-06-15 11:31
|*                                                          *|
\************************************************************/

#include "MainMenuState.hpp"
#include "OptionMenuState.hpp"

OptionMenuState::OptionMenuState(ApplicationState *parent) : ApplicationState("OptionMenu", parent) {
	m_trayManager->createButton(OgreBites::TL_CENTER, "return", "Return", 200);
}

void OptionMenuState::update() {
}

void OptionMenuState::buttonHit(OgreBites::Button *button) {
	if (button->getName() == "return") {
		// m_trayManager->destroyAllWidgetsInTray(OgreBites::TrayLocation::TL_CENTER);
		m_stateStack->pop();
		m_parent->show();
	}
}
