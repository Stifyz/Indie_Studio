/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* ChatState.cpp for project :
|*                                                          *|
|* Created: 2017-06-18 01:19
|*                                                          *|
\************************************************************/

#include "ChatState.hpp"

#include "GamePad.hpp"

#include <SDLHeaders.hpp>

ChatState::ChatState(ApplicationState *parent) : ApplicationState("Chat", parent) {
	m_textBox.init(m_trayManager->createTextBox(OgreBites::TL_BOTTOMRIGHT, "ChatBox_WR", "", 750, 500));
	OgreData::getInstance().keyboardIsTextMod = true;
}

void ChatState::update() {
	if (!m_textBox.write(firstTurn)) {
		OgreData::getInstance().keyboardIsTextMod = false;
		m_stateStack->pop();
		m_parent->show();
		return ;
	}
	else
		m_textBox.update();
	firstTurn = false;
}

void ChatState::buttonHit(OgreBites::Button *button) {
}
