/*
 * =====================================================================================
 *
 *       Filename:  EnemyMovement.cpp
 *
 *    Description:
 *
 *        Created:  19/06/2017 15:29:08
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <cmath>

#include "EnemyMovement.hpp"
#include "MovementComponent.hpp"
#include "RadarComponent.hpp"
#include "SceneNodeComponent.hpp"

void EnemyMovement::process(SceneObject &object) {
	SceneObject *nearestPlayer = object.get<RadarComponent>().neareastObject;
	if (nearestPlayer) {
		Ogre::Vector3 objectPosition = object.get<SceneNodeComponent>().root->getPosition();
		Ogre::Vector3 playerPosition = nearestPlayer->get<SceneNodeComponent>().root->getPosition();

		Ogre::Vector3 diff = playerPosition - objectPosition;

		diff.x = floor(diff.x);
		diff.y = floor(diff.y);
		diff.z = floor(diff.z);

		diff.x = (diff.x) ? diff.x / std::fabs(diff.x) : 0;
		diff.y = (diff.y) ? diff.y / std::fabs(diff.y) : 0;
		diff.z = (diff.z) ? diff.z / std::fabs(diff.z) : 0;

		auto &movementComponent = object.get<MovementComponent>();
		movementComponent.v = diff;
	}
}

