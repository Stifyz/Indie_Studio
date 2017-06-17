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
#include "DiabolousAttackBehaviour.hpp"
#include "GamePad.hpp"
// #include "Mouse.hpp"

void DiabolousAttackBehaviour::update(SceneObject &object) {
	auto &animationListComponent = object.get<AnimationListComponent>();
	//        if (Mouse::isButtonPressed(Mouse::Button::Left) && animationListComponent.isAnimationFinished("Attack")) {
     	if (GamePad::isKeyPressed(GameKey::A) && animationListComponent.isAnimationFinished("Attack")) {
		if (animationListComponent.getActiveAnimation(0) != std::string("Attack"))
			m_previousActiveAnimation = animationListComponent.getActiveAnimation(0);
		animationListComponent.setActiveAnimation(0, "Attack", true)->timer.setTime(6);
	}
}

void DiabolousAttackBehaviour::animationEndCallback(AnimationListComponent &animationListComponent, const Animation &animation) const {
	if (animation.name == "Attack") {
		animationListComponent.setActiveAnimation(0, m_previousActiveAnimation);
	}
}

