/*
 * =====================================================================================
 *
 *       Filename:  SpawnerFactory.cpp
 *
 *    Description:
 *
 *        Created:  17/06/2017 15:39:03
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "BehaviourComponent.hpp"
#include "CollisionComponent.hpp"
#include "GameClock.hpp"
#include "EasyBehaviour.hpp"
#include "EntityListComponent.hpp"
#include "HealthComponent.hpp"
#include "LifeBarBehaviour.hpp"
#include "LifetimeComponent.hpp"
#include "SpawnerComponent.hpp"
#include "SpawnerFactory.hpp"
#include "SceneNodeComponent.hpp"

static unsigned long int spawnerCount = 0;

SceneObject SpawnerFactory::create(const Ogre::Vector3 &pos) {
	SceneObject object{"Spawner" + std::to_string(spawnerCount++), "Enemy"};
	object.set<CollisionComponent>();
	object.set<SpawnerComponent>(10, 8000, 2, 4);

	auto &healthComponent = object.set<HealthComponent>(600, 600, 100);
	object.set<LifetimeComponent>([&] (SceneObject &object) {
		return healthComponent.life() == 0;
	});

	auto &bodyNodeComponent = object.set<SceneNodeComponent>(pos, Ogre::Vector3(0.01, 0.01, 0.01));
	bodyNodeComponent.node->pitch(Ogre::Degree(90));

	auto &entityListComponent = object.set<EntityListComponent>(bodyNodeComponent.node);
	entityListComponent.addEntity(object.name() + "Body", "Skull.mesh", true);

	auto &behaviourComponent = object.set<BehaviourComponent>();
	behaviourComponent.addBehaviour<LifeBarBehaviour>("LifeBar", bodyNodeComponent.root, Ogre::Vector3(0, 6, 0));
	behaviourComponent.addBehaviour<EasyBehaviour>("Animation", [pos] (SceneObject &object) {
		object.get<SceneNodeComponent>().root->setPosition(pos + Ogre::Vector3::UNIT_Y * (cos(GameClock::getTicks() * 0.003) / 4) + 1);
	});

	return object;
}
