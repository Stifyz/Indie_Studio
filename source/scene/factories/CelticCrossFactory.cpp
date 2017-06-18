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
#include "BehaviourComponent.hpp"
#include "CollisionComponent.hpp"
#include "EasyBehaviour.hpp"
#include "EntityListComponent.hpp"
#include "CelticCrossFactory.hpp"
#include "SceneNodeComponent.hpp"

static unsigned long int celticCrossCount = 0;

SceneObject CelticCrossFactory::create(const Ogre::Vector3 &pos) {
	SceneObject object{"CelticCross" + std::to_string(celticCrossCount++)};
	object.set<CollisionComponent>();

	auto &bodyNodeComponent = object.set<SceneNodeComponent>(pos, Ogre::Vector3(1.5, 1.5, 1.5));

	auto &entityListComponent = object.set<EntityListComponent>(bodyNodeComponent.node);
	entityListComponent.addEntity(object.name() + "Body", "CelticCross.mesh", true);

	auto &behaviourComponent = object.set<BehaviourComponent>();
	behaviourComponent.addBehaviour<EasyBehaviour>("Animation", [] (SceneObject &object) {
	});

	return object;
}

