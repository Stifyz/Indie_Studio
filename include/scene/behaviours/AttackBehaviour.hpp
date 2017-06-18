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
#include "AudioPlayer.hpp"
#include "Behaviour.hpp"

class AttackBehaviour : public Behaviour {
	using ConditionCallback = std::function<bool(SceneObject &)>;

	public:
		AttackBehaviour(const char *animName) : m_animName(animName) {}

		void update(SceneObject &object) override;

		virtual void action(SceneObject &object) {}

		virtual void animationEndCallback(AnimationListComponent &animationListComponent, const Animation &animation) const;

		void setCondition(const ConditionCallback &conditionCallback) {
			m_conditionCallback = conditionCallback;
		};

	private:
		std::string m_animName;

		const char *m_previousActiveAnimation = nullptr;

		ConditionCallback m_conditionCallback;
};

#endif // ATTACKBEHAVIOUR_HPP_
