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
		void init(const std::string &fileName, const std::string &sceneName);
		void set(const std::string &, const std::string &);
		void update();

	private:
		std::unique_ptr<Ogre::Rectangle2D> m_rect = nullptr;
};

#endif // !BACKGROUND_HPP_
