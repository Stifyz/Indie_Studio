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
#ifndef ARCHERSHOOTBEHAVIOUR_HPP_
#define ARCHERSHOOTBEHAVIOUR_HPP_

#include "AnimationListComponent.hpp"
#include "Behaviour.hpp"

class ArcherShootBehaviour : public Behaviour {
	public:
		void update(SceneObject &object) override;

		void animationEndCallback(AnimationListComponent &animationListComponent, const Animation &animation) const;

	private:
		const char *m_previousActiveAnimation = nullptr;
};

#endif // ARCHERSHOOTBEHAVIOUR_HPP_
