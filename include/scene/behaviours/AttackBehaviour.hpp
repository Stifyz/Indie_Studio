/*
 * =====================================================================================
 *
 *       Filename:  AttackBehaviour.hpp
 *
 *    Description:
 *
 *        Created:  18/06/2017 03:15:18
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ATTACKBEHAVIOUR_HPP_
#define ATTACKBEHAVIOUR_HPP_

#include "AnimationListComponent.hpp"
#include "Behaviour.hpp"

class AttackBehaviour : public Behaviour {
	public:
		void update(SceneObject &object) override;

		virtual void action(SceneObject &object) {}

		virtual void animationEndCallback(AnimationListComponent &animationListComponent, const Animation &animation) const;

	private:
		const char *m_previousActiveAnimation = nullptr;
};

#endif // ATTACKBEHAVIOUR_HPP_
