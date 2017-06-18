/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* HudManager.cpp for project :
|*                                                          *|
|* Created: 2017-06-18 20:36
|*                                                          *|
\************************************************************/

#include "Exception.hpp"
#include "HudManager.hpp"
#include "HealthComponent.hpp"
#include "ScoreComponent.hpp"

void HudManager::init(OgreBites::TrayManager *trayManager) {
	m_trayManager = trayManager;
	m_trayManager->createProgressBar(OgreBites::TL_TOPRIGHT, "Skull_coin_bar", "Skull Coins", 300, 100);
}

void HudManager::addPlayer(const SceneObject &player) {
	if (!player.has<HealthComponent>() || !player.has<ScoreComponent>())
		throw EXCEPTION("Player need health and score component for create his HUD");

	// m_players.emplace_back(std::make_pair(&player.get<HealthComponent>(), &player.get<ScoreComponent>()));

	std::string wName = "PlayerInfoBar_" + std::to_string(m_players.size());
	auto *infoBar = m_trayManager->createProgressBar(OgreBites::TL_LEFT, wName, player.name(), 200, 100);
	infoBar->setProgress(0);
	infoBar->setComment(" Gold : ");

	// auto &behaviourComponent = player.get<BehaviourComponent>();
	// m_infoBars.push_back(infoBar);
}

// void HudManager::removePlayer(const SceneObject &player) {}

// void HudManager::update() {
// 	for (std::size_t i = 0; i < m_players.size(); ++i) {
// 		if (m_players[i].get().has<HealthComponent>() && m_players[i].get().has<ScoreComponent>()) {
// 			const auto &healthComponent = *m_players[i].first;
// 			const auto &scoreComponent = *m_players[i].second;
//
// 			m_infoBars[i]->setProgress((float)healthComponent.life() / healthComponent.maxLife());
// 			m_infoBars[i]->setComment(" Gold : " + std::to_string(scoreComponent.gold));
// 		}
// 	}
// }
