/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* ChatState.hpp for project :
|*                                                          *|
|* Created: 2017-06-18 01:20
|*                                                          *|
\************************************************************/

#ifndef CHATSTATE_HPP_
#define CHATSTATE_HPP_

#include "ApplicationState.hpp"
#include "TextBox.hpp"

class ChatState : public ApplicationState {
	public:
		ChatState(ApplicationState *parent);

		void update();
		void buttonHit(OgreBites::Button *button);
	private:
		TextBox m_textBox;
		bool firstTurn = true;
};

#endif // !CHATSTATE_HPP_
