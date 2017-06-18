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
#include "LifetimeComponent.hpp"
#include "LifetimeSystem.hpp"
#include "MovementSystem.hpp"
#include "SceneSystem.hpp"
#include "SpawnerSystem.hpp"
#include "RadarSystem.hpp"

void SceneSystem::reset(SceneObjectList &objectList) {
	for(auto &object : objectList) resetObject(object);
}

void SceneSystem::update(SceneObjectList &objectList) {
	LifetimeSystem::process(objectList);
	SpawnerSystem::process(objectList);
	RadarSystem::process(objectList);

	unsigned long int enemyCount = 0;
	unsigned long int playerCount = 0;
	for(auto &object : objectList) {
		if (object.type() == "Enemy")  ++enemyCount;
		if (object.type() == "Player") ++playerCount;

		updateObject(object);
	}

	objectList.setEnemyCount(enemyCount);
	objectList.setPlayerCount(playerCount);
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

