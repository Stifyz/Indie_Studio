/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* HudManager.hpp for project :
|*                                                          *|
|* Created: 2017-06-18 20:35
|*                                                          *|
\************************************************************/

#ifndef HUDMANAGER_HPP_
#define HUDMANAGER_HPP_

#include <OgreTrays.h>

class HudManager {
	public:
		void init(OgreBites::TrayManager *);

	private:
		OgreBites::TrayManager *m_trayManager;

};

#endif // !HUDMANAGER_HPP_
