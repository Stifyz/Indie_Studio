/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* TextBox.hpp for project :
|*                                                          *|
|* Created: 2017-06-18 01:23
|*                                                          *|
\************************************************************/

#ifndef TEXTBOX_HPP_
#define TEXTBOX_HPP_

#include "OgreTrays.h"

class TextBox {
	public:
		void init(OgreBites::TextBox *textBox);

		bool write(bool firstTurn);
		void newLine(const std::string &);

		const std::string &getText();
		void setText(const std::string &);

		void saveBuffer();

		void update();
	private:
		OgreBites::TextBox *m_textBox;
};

#endif // !TEXTBOX_HPP_
