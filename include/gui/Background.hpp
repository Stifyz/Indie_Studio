/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* Background.hpp for project :
|*                                                          *|
|* Created: 2017-06-15 13:40
|*                                                          *|
\************************************************************/

#ifndef BACKGROUND_HPP_
#define BACKGROUND_HPP_

#include <string>
#include <OgreRectangle2D.h>

class Background {
	public:
		~Background() { delete m_rect; }
		void init(const std::string &filename, const std::string &objectName);
		void set();
		void update();

	private:
		std::string m_filename;
		std::string m_objectName;
		Ogre::Rectangle2D *m_rect;
};

#endif // !BACKGROUND_HPP_
