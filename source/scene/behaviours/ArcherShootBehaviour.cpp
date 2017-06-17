/*
 * =====================================================================================
 *
 *       Filename:  ArcherShootBehaviour.cpp
 *
 *    Description:
 *
 *        Created:  16/06/2017 08:47:10
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "AnimationListComponent.hpp"
#include "ArcherShootBehaviour.hpp"
#include "Mouse.hpp"

void ArcherShootBehaviour::update(SceneObject &object) {
	auto &animationListComponent = object.get<AnimationListComponent>();
	if (Mouse::isButtonPressedOnce(Mouse::Button::Left) && animationListComponent.isAnimationFinished("Attack")) {
		m_previousActiveAnimation = animationListComponent.getActiveAnimation(0);
		animationListComponent.setActiveAnimation(0, "Attack", true);
	}
}

void ArcherShootBehaviour::animationEndCallback(AnimationListComponent &animationListComponent, const Animation &animation) const {
	if (animation.name == "Attack") {
		animationListComponent.setActiveAnimation(0, m_previousActiveAnimation);
	}
}

