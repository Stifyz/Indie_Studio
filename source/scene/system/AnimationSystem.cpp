/*
 * =====================================================================================
 *
 *       Filename:  AnimationSystem.cpp
 *
 *    Description:
 *
 *        Created:  29/05/2017 10:52:15
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "AnimationListComponent.hpp"
#include "AnimationSystem.hpp"

void AnimationSystem::process(SceneObject &object) {
	if (object.has<AnimationListComponent>()) {
		auto &animationListComponent = object.get<AnimationListComponent>();
		animationListComponent.updateActiveAnimations();
		animationListComponent.fadeAnimations();
	}
}

