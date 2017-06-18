/*
 * =====================================================================================
 *
 *       Filename:  RadarSystem.cpp
 *
 *    Description:
 *
 *        Created:  19/06/2017 16:14:13
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */

#include "DamageComponent.hpp"
#include "HealthComponent.hpp"
#include "RadarComponent.hpp"
#include "RadarSystem.hpp"
#include "SceneNodeComponent.hpp"

void RadarSystem::process(SceneObjectList &objectList) {
	for (SceneObject &object : objectList) {
		if (object.has<RadarComponent>()) {
			auto &radarComponent = object.get<RadarComponent>();

			Ogre::Real smallestDistance = 10000;
			for (SceneObject &object2 : objectList) {
				if (&object != &object2 && (radarComponent.nameFilter == "any" || radarComponent.nameFilter == object2.name())
				                        && (radarComponent.typeFilter == "any" || radarComponent.typeFilter == object2.type())) {
					Ogre::SceneNode *node1 = object.get<SceneNodeComponent>().root;
					Ogre::SceneNode *node2 = object2.get<SceneNodeComponent>().root;

					Ogre::Real distance = node1->getPosition().distance(node2->getPosition());
					if (distance < smallestDistance) {
						smallestDistance = distance;

						radarComponent.neareastObjectDistance = smallestDistance;
						radarComponent.neareastObject = &object2;
					}
				}
			}
		}
	}
}

