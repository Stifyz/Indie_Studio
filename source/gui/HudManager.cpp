/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* HudManager.cpp for project :
|*                                                          *|
|* Created: 2017-06-18 20:36
|*                                                          *|
\************************************************************/

#include "HudManager.hpp"

void HudManager::init(OgreBites::TrayManager *trayManager) {
	m_trayManager = trayManager;
	m_trayManager->createProgressBar(OgreBites::TL_TOPRIGHT, "Skull_coin_bar", "Skull Coins", 300, 0);
}
