/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* MenuState.cpp for project :
|*                                                          *|
|* Created: 2017-06-07 15:38
|*                                                          *|
\************************************************************/

#include "MenuState.hpp"

MenuState::MenuState(OgreBites::TrayManager *trayManager) {
  m_menuManager.reset(trayManager);
}

void MenuState::loadMenu(const MenuState::MenuType menuType) {
  m_actMenu = menuType;
  (this->*m_menu.at(menuType))();
}

void MenuState::setMain() {
  m_menuManager->createButton(OgreBites::TL_CENTER, "Start Game", "Start Game", 200);
  m_menuManager->createButton(OgreBites::TL_CENTER, "Settings", "Settings", 200);
  m_menuManager->createButton(OgreBites::TL_CENTER, "How To Play", "How To Play", 200);
  m_menuManager->createButton(OgreBites::TL_CENTER, "Quit", "Quit", 200);
}

void MenuState::setGame() {
	m_menuManager->showFrameStats(OgreBites::TL_BOTTOMLEFT);
	m_menuManager->showLogo(OgreBites::TL_BOTTOMRIGHT);
	m_menuManager->showCursor();
}

void MenuState::setSettings() {
  m_menuManager->createButton(OgreBites::TL_CENTER, "Keyboards", "Keyboards", 200);
  m_menuManager->createButton(OgreBites::TL_CENTER, "Sounds", "Sounds", 200);
  m_menuManager->createButton(OgreBites::TL_CENTER, "Graphics", "Graphics", 200);
  m_menuManager->createButton(OgreBites::TL_CENTER, "Return", "Return", 200);
}

void MenuState::setHowToPlay() {
  m_menuManager->createButton(OgreBites::TL_CENTER, "Help", "Help", 200);
  m_menuManager->createButton(OgreBites::TL_CENTER, "Rules", "Rules", 200);
  m_menuManager->createButton(OgreBites::TL_CENTER, "Inputs", "Inputs", 200);
  m_menuManager->createButton(OgreBites::TL_CENTER, "Return", "Return", 200);
}

bool MenuState::keyPressed(const OgreBites::KeyboardEvent& evt) {
  if (evt.keysym.sym == SDLK_F1) {
    loadMenu(MenuType::Game);
	return true;
  }
  return false;
}

bool MenuState::keyReleased(const OgreBites::KeyboardEvent& evt) {
  return true;
}

bool MenuState::mouseMoved(const OgreBites::MouseMotionEvent& evt) {
  return true;
}

bool MenuState::mouseWheelRolled(const OgreBites::MouseWheelEvent& evt) {
  return true;
}

bool MenuState::mousePressed(const OgreBites::MouseButtonEvent& evt) {
  return true;
}

void MenuState::update() {

}
