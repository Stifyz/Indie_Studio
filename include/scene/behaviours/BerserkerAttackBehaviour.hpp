/*
 * =====================================================================================
 *
 *       Filename:  ArcherShootBehaviour.hpp
 *
 *    Description:
 *
 *        Created:  16/06/2017 08:44:35
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BERSERKERATTACKBEHAVIOUR_HPP_
#define BERSERKERATTACKBEHAVIOUR_HPP_

#include "AnimationListComponent.hpp"
#include "Behaviour.hpp"

class BerserkerAttackBehaviour : public Behaviour {
	public:
		void update(SceneObject &object) override;

		void animationEndCallback(AnimationListComponent &animationListComponent, const Animation &animation) const;

	private:
		const char *m_previousActiveAnimation = nullptr;
};

#endif // BERSERKERATTACKBEHAVIOUR_HPP_
