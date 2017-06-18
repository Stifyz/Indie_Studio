/*
 * =====================================================================================
 *
 *       Filename:  HealthComponent.hpp
 *
 *    Description:
 *
 *        Created:  18/06/2017 19:20:53
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef HEALTHCOMPONENT_HPP_
#define HEALTHCOMPONENT_HPP_

#include "IntTypes.hpp"

class HealthComponent {
	public:
		HealthComponent(u8 maxLife, u8 life = 0)
			: m_maxLife(maxLife), m_life(life ? life : maxLife) {}

		void setLife(u8 newLife) { m_life = (newLife > m_maxLife) ? m_maxLife : newLife; }
		void addLife(u8 lifeAdded) { setLife(m_life + lifeAdded); }
		void removeLife(u8 lifeRemoved) { (lifeRemoved > m_life) ? setLife(0) : setLife(m_life - lifeRemoved); }

		u8 life() const { return m_life; }
		u8 maxLife() const { return m_maxLife; }

	private:
		u8 m_maxLife = 0;
		u8 m_life = 0;

};

#endif // HEALTHCOMPONENT_HPP_
