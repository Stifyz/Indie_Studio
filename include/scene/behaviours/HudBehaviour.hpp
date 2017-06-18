/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* HudBehaviour.hpp for project :
|*                                                          *|
|* Created: 2017-06-21 14:39
|*                                                          *|
\************************************************************/

#ifndef HUDBEHAVIOUR_HPP_
#define HUDBEHAVIOUR_HPP_

#include "Behaviour.hpp"

#include "HealthComponent.hpp"
#include "ScoreComponent.hpp"

#include <OgreTrays.h>

class HudBehaviour : public Behaviour {
	public:
		HudBehaviour(OgreBites::ProgressBar *bar) : m_bar(bar) {};
		void update(SceneObject &object) override {
			if (object.has<HealthComponent>() && object.has<ScoreComponent>()) {
				const auto &healthComponent = object.get<HealthComponent>();
				const auto &scoreComponent = object.get<ScoreComponent>();

				m_bar->setProgress((float)healthComponent.life() / healthComponent.maxLife());
				m_bar->setComment("Gold: " + std::to_string(scoreComponent.gold));
			}
		}
		virtual void action(SceneObject &object) {

		}

	private:
		OgreBites::ProgressBar *m_bar;
};

#endif // !HUDBEHAVIOUR_HPP_
