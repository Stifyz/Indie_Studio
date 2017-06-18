/*
 * =====================================================================================
 *
 *       Filename:  HeartFactory.cpp
 *
 *    Description:
 *
 *        Created:  17/06/2017 15:39:03
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "BehaviourComponent.hpp"
#include "CollisionComponent.hpp"
#include "EasyBehaviour.hpp"
#include "EntityListComponent.hpp"
#include "HealthComponent.hpp"
#include "HeartFactory.hpp"
#include "LifetimeComponent.hpp"
#include "SceneNodeComponent.hpp"

static unsigned long int heartCount = 0;

SceneObject HeartFactory::create(const Ogre::Vector3 &pos) {
	SceneObject object{"Heart" + std::to_string(heartCount++)};
	object.set<CollisionComponent>().addAction(&HeartFactory::heartAction);
	object.set<LifetimeComponent>();

	auto &bodyNodeComponent = object.set<SceneNodeComponent>(pos, Ogre::Vector3(3, 3, 3));
	bodyNodeComponent.node->pitch(Ogre::Degree(90));

	auto &entityListComponent = object.set<EntityListComponent>(bodyNodeComponent.node);
	entityListComponent.addEntity(object.name() + "Body", "Heart.mesh", true);

	auto &behaviourComponent = object.set<BehaviourComponent>();
	behaviourComponent.addBehaviour<EasyBehaviour>("Animation", [] (SceneObject &object) {
		object.get<SceneNodeComponent>().node->roll(Ogre::Degree(0.2));
	});

	return object;
}

void HeartFactory::heartAction(SceneObject &heart, SceneObject &object, const CollisionInfo &info) {
	if (info.inCollision && object.type() == "Player" && !heart.get<LifetimeComponent>().dead(heart)) {
		object.get<HealthComponent>().addLife(50);
		heart.get<LifetimeComponent>().kill();

		AudioPlayer::playEffect("eat1");
	}
}

