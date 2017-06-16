/*
 * =====================================================================================
 *
 *       Filename:  BehaviourSystem.cpp
 *
 *    Description:
 *
 *        Created:  16/06/2017 08:40:25
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "BehaviourComponent.hpp"
#include "BehaviourSystem.hpp"

void BehaviourSystem::process(SceneObject &object) {
	if (object.has<BehaviourComponent>()) {
		object.get<BehaviourComponent>().updateBehaviours(object);
	}
}

void BehaviourSystem::reset(SceneObject &object) {
	// FIXME: TODO
}

