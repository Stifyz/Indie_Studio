/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* TextBox.cpp for project :
|*                                                          *|
|* Created: 2017-06-18 01:23
|*                                                          *|
\************************************************************/

#include <algorithm>
#include <string>

#include <SDLHeaders.hpp>

#include "ChatState.hpp"
#include "GamePad.hpp"
#include "OgreData.hpp"
#include "TextBox.hpp"

#include "TextMsg.hpp"

#include "Debug.hpp"

void TextBox::init(OgreBites::TextBox *textBox) {
	m_textBox = textBox;
	auto &s = OgreData::getInstance().chatBuffer();
	m_textBox->setText(s);
}

bool TextBox::write(bool isFirstTurn) {
	const OgreBites::KeyboardEvent *evt = OgreData::getInstance().getLastPressed();
	if (!evt)
		return true;

	unsigned char c = static_cast<unsigned char>(evt->keysym.sym);
	std::string str;
	str = c;
	// DEBUG("MY VALUE", static_cast<unsigned int>(static_cast<unsigned char>(evt->keysym.sym)));
	// DEBUG("MY STR", str);
	// if (c == 27) {
	// 	return false;
	// }
	if (c == 9 && !isFirstTurn) {
		return false;
	}
	if (c == 8)
	{
		std::string str2 = m_textBox->getCaption();
		if (str2.size() > 0)
		{
			str2.pop_back();
			m_textBox->setCaption(str2);
		}
	}
	else if (c == 13) {
		INetwork *network = OgreData::getInstance().network();
		chat::TextMsg msg(network->id(), m_textBox->getCaption(), chat::PUBLIC);
		network->send(com::Packet(network->id(), com::CHAT, msg));
		newLine(m_textBox->getCaption());
		m_textBox->setCaption("");
	}
	else if (c < ' ' || c > 126 || (c > 64 && c < 91))
		return true;
	else
		m_textBox->setCaption(m_textBox->getCaption() + str);
	return true;
}

void TextBox::newLine(const std::string &str) {
	auto &s = OgreData::getInstance().chatBuffer();
	s += "\n" + str;
}

const std::string &TextBox::getText() {
	const std::string &str = OgreData::getInstance().chatBuffer();
	return str;
}

void TextBox::setText(const std::string &str) {
	auto &s = OgreData::getInstance().chatBuffer();
	s = str;
}

void TextBox::update() {
	// remove the line after the 100th
	auto &s = OgreData::getInstance().chatBuffer();
	while (std::count(s.begin(), s.end(), '\n') > 100) {
		s = s.substr(0, s.rfind('\n'));
	}
	m_textBox->setText(s);

	// Keep scroll down in RO box
	if (m_textBox->getName() == "ChatBox_RO" &&
			std::count(s.begin(), s.end(), '\n') > m_textBox->getHeightInLines())
		m_textBox->setScrollPercentage(1);
}
