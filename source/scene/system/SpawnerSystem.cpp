/*
 * =====================================================================================
 *
 *       Filename:  SpawnerSystem.cpp
 *
 *    Description:
 *
 *        Created:  20/06/2017 14:23:50
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <OgreMath.h>

#include "DiabolousFactory.hpp"
#include "SceneNodeComponent.hpp"
#include "SpawnerComponent.hpp"
#include "SpawnerSystem.hpp"

void SpawnerSystem::process(SceneObjectList &objectList) {
	SceneObjectList objectsToAdd;
	for (SceneObject &object : objectList) {
		if (object.has<SpawnerComponent>()) {
			auto &spawnerComponent = object.get<SpawnerComponent>();
			if (spawnerComponent.canSpawn()) {
				for (u16 i = 0 ; i < spawnerComponent.getRandomWaveCount() ; ++i) {
					Ogre::Vector3 spawnerPosition = object.get<SceneNodeComponent>().root->getPosition();

					Ogre::Radian angle = Ogre::Degree(rand() % 360);
					Ogre::Vector3 direction = Ogre::Vector3(Ogre::Math::Cos(angle), 0, Ogre::Math::Sin(angle));

					Ogre::Ray ray(spawnerPosition, direction);
					objectsToAdd.addObject(DiabolousFactory::create(ray.getPoint(spawnerComponent.getRandomRange())));
				}

				spawnerComponent.resetTimer();
			}
		}
	}

	for (SceneObject &object : objectsToAdd) {
		objectList.addObject(std::move(object));
	}
}

