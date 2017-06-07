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

Ui::Ui(OgreBites::TrayManager *trayManager) : m_uiManager(trayManager) {
	m_actMenu = MenuType::Main;
}

void Ui::launch(const Ui::MenuType menuType) {
	m_actMenu = menuType;
	(this->*m_menu[menuType])();
}

void Ui::clear() const {
	m_uiManager->clearAllTrays();
}

void Ui::refresh() {
	clear();
	launch(m_actMenu);
}

void	Ui::setMain() {
  m_uiManager->createButton(OgreBites::TL_CENTER, "Start Game", "Start Game", 200);
  m_uiManager->createButton(OgreBites::TL_CENTER, "Settings", "Settings", 200);
  m_uiManager->createButton(OgreBites::TL_CENTER, "How To Play", "How To Play", 200);
  m_uiManager->createButton(OgreBites::TL_CENTER, "Quit", "Quit", 200);
}

void	Ui::setSettings() {
  m_uiManager->createButton(OgreBites::TL_CENTER, "Keyboards", "Keyboards", 200);
  m_uiManager->createButton(OgreBites::TL_CENTER, "Sounds", "Sounds", 200);
  m_uiManager->createButton(OgreBites::TL_CENTER, "Graphics", "Graphics", 200);
  m_uiManager->createButton(OgreBites::TL_CENTER, "Return", "Return", 200);
}

void	Ui::howtoplay() {
  m_uiManager->createButton(OgreBites::TL_CENTER, "Help", "Help", 200);
  m_uiManager->createButton(OgreBites::TL_CENTER, "Rules", "Rules", 200);
  m_uiManager->createButton(OgreBites::TL_CENTER, "Inputs", "Inputs", 200);
  m_uiManager->createButton(OgreBites::TL_CENTER, "Return", "Return", 200);
}
