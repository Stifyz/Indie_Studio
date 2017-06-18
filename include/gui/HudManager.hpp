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

#include "SceneObject.hpp"

class HealthComponent;
class ScoreComponent;

class HudManager {
	public:
		void init(OgreBites::TrayManager *);

		void addPlayer(const SceneObject &player);

		void update();

	private:
		std::vector<std::pair<HealthComponent *, ScoreComponent *>> m_players;

		OgreBites::TrayManager *m_trayManager;
		std::vector<OgreBites::ProgressBar *> m_infoBars;
};

#endif // !HUDMANAGER_HPP_
