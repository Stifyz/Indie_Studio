/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* Menu.cpp for project :
|*                                                          *|
|* Created: 2017-06-07 15:38
|*                                                          *|
\************************************************************/

#include "Ui.hpp"

Ui::Ui() {
	m_actMenu = MenuType::Main;
}

OgreBites::TrayManager *Ui::create(const Ui::MenuType menuType, Ogre::RenderWindow *window) {
	OgreBites::TrayManager *trayManager = new OgreBites::TrayManager("TrayManager", window);
	m_actMenu = menuType;
	(this->*m_menu.at(menuType))(trayManager);
	return trayManager;
}

void Ui::setMain(OgreBites::TrayManager *trayManager) {
  trayManager->createButton(OgreBites::TL_CENTER, "Start Game", "Start Game", 200);
  trayManager->createButton(OgreBites::TL_CENTER, "Settings", "Settings", 200);
  trayManager->createButton(OgreBites::TL_CENTER, "How To Play", "How To Play", 200);
  trayManager->createButton(OgreBites::TL_CENTER, "Quit", "Quit", 200);
}

void Ui::setGame(OgreBites::TrayManager *trayManager) {
	trayManager->showFrameStats(OgreBites::TL_BOTTOMLEFT);
	trayManager->showLogo(OgreBites::TL_BOTTOMRIGHT);
	trayManager->showCursor();
}

void Ui::setSettings(OgreBites::TrayManager *trayManager) {
  trayManager->createButton(OgreBites::TL_CENTER, "Keyboards", "Keyboards", 200);
  trayManager->createButton(OgreBites::TL_CENTER, "Sounds", "Sounds", 200);
  trayManager->createButton(OgreBites::TL_CENTER, "Graphics", "Graphics", 200);
  trayManager->createButton(OgreBites::TL_CENTER, "Return", "Return", 200);
}

void Ui::setHowToPlay(OgreBites::TrayManager *trayManager) {
  trayManager->createButton(OgreBites::TL_CENTER, "Help", "Help", 200);
  trayManager->createButton(OgreBites::TL_CENTER, "Rules", "Rules", 200);
  trayManager->createButton(OgreBites::TL_CENTER, "Inputs", "Inputs", 200);
  trayManager->createButton(OgreBites::TL_CENTER, "Return", "Return", 200);
}
