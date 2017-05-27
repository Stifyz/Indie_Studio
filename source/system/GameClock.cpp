/*
 * =====================================================================================
 *
 *       Filename:  GameClock.cpp
 *
 *    Description:
 *
 *        Created:  24/05/2017 13:55:40
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <SDL2/SDL.h>

#include "GameClock.hpp"

u32 GameClock::s_ticks = 0;

void GameClock::updateGame(std::function<void(void)> updateFunc) {
	m_numUpdates = 0;

	while (m_lag >= m_timestep && m_numUpdates < 10) {
		s_ticks += m_timestep;

		updateFunc();

		m_lag -= m_timestep;
		m_numUpdates++;
	}
}

void GameClock::drawGame(std::function<void(void)> drawFunc) {
	if (m_numUpdates > 0) {
		drawFunc();
	}

	u32 lastFrameDuration = getTicks(true) - m_timeDropped - m_lastFrameBegin;

	if (lastFrameDuration < m_timestep) {
		SDL_Delay(m_timestep - lastFrameDuration);
	}

	measureLastFrameDuration();
}

u32 GameClock::getTicks(bool realTime) {
	if (realTime) {
		return SDL_GetTicks();
	} else {
		return s_ticks;
	}
}

void GameClock::measureLastFrameDuration() {
	u32 now = getTicks(true) - m_timeDropped;
	u32 lastFrameDuration = now - m_lastFrameBegin;

	m_lastFrameBegin = now;
	m_lag += lastFrameDuration;

	if (m_lag >= 200) {
		m_timeDropped += m_lag - m_timestep;
		m_lag = m_timestep;
		m_lastFrameBegin = getTicks(true) - m_timeDropped;
	}
}

