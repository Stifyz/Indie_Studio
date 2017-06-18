/*
 * =====================================================================================
 *
 *       Filename:  SpawnerComponent.hpp
 *
 *    Description:
 *
 *        Created:  20/06/2017 14:22:26
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SPAWNERCOMPONENT_HPP_
#define SPAWNERCOMPONENT_HPP_

#include <cmath>

#include "Timer.hpp"

class SpawnerComponent {
	public:
		SpawnerComponent(const u16 maxRange, const u16 delay, const u16 minWave, const u16 maxWave)
			: m_maxRange(maxRange), m_delay(delay), m_minWave(minWave), m_maxWave(maxWave) {
			m_timer.start();
		}

		void resetTimer() {
			m_timer.reset();
			m_timer.start();
		}

		u16 getRandomRange() const { return 3 + (rand() % (m_maxRange - 3)); }
		u16 getRandomWaveCount() const { return m_minWave + (rand() % (m_maxWave - m_minWave + 1)); }

		bool canSpawn() const { return m_timer.time() > m_delay; }

	private:
		u16 m_maxRange;

		u16 m_delay;
		Timer m_timer;

		u16 m_minWave;
		u16 m_maxWave;
};

#endif // SPAWNERCOMPONENT_HPP_
