/*
 * =====================================================================================
 *
 *       Filename:  AttackBehaviour.cpp
 *
 *    Description:
 *
 *        Created:  18/06/2017 03:18:15
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "AttackBehaviour.hpp"
#include "GamePad.hpp"

void AttackBehaviour::update(SceneObject &object) {
	auto &animationListComponent = object.get<AnimationListComponent>();
	// if (Mouse::isButtonPressed(Mouse::Button::Left) && animationListComponent.isAnimationFinished("Attack")) {
	if ((!m_conditionCallback || m_conditionCallback(object)) && animationListComponent.isAnimationFinished(m_animName.c_str())) {
		if (animationListComponent.getActiveAnimation(0) != m_animName)
			m_previousActiveAnimation = animationListComponent.getActiveAnimation(0);
		animationListComponent.setActiveAnimation(0, m_animName.c_str(), true)->timer.setTime(6);
		action(object);
	}
}

void AttackBehaviour::animationEndCallback(AnimationListComponent &animationListComponent, const Animation &animation) const {
	animationListComponent.setActiveAnimation(0, m_previousActiveAnimation);
}

