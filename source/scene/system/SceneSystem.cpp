/*
 * =====================================================================================
 *
 *       Filename:  SceneSystem.cpp
 *
 *    Description:
 *
 *        Created:  20/04/2017 22:51:38
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "AnimationSystem.hpp"
#include "BehaviourSystem.hpp"
#include "MovementSystem.hpp"
#include "SceneSystem.hpp"

void SceneSystem::reset(SceneObjectList &objectList) {
	for(auto &object : objectList) resetObject(object);
}

void SceneSystem::update(SceneObjectList &objectList) {
	for(auto &object : objectList) updateObject(object);
}

void SceneSystem::resetObject(SceneObject &object) {
	BehaviourSystem::reset(object);

	if(object.has<SceneObjectList>()) {
		reset(object.get<SceneObjectList>());
	}
}

void SceneSystem::updateObject(SceneObject &object) {
	AnimationSystem::process(object);
	BehaviourSystem::process(object);
	MovementSystem::process(object);

	if(object.has<SceneObjectList>()) {
		update(object.get<SceneObjectList>());
	}
}

