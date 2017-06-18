/*
 * =====================================================================================
 *
 *       Filename:  ArrowFactory.cpp
 *
 *    Description:
 *
 *        Created:  18/06/2017 02:49:32
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "ArrowFactory.hpp"
#include "CollisionComponent.hpp"
#include "EasyBehaviour.hpp"
#include "EasyMovement.hpp"
#include "EntityListComponent.hpp"
#include "MovementComponent.hpp"
#include "SceneNodeComponent.hpp"

SceneObject ArrowFactory::create(const Ogre::Vector3 &pos, const Ogre::Vector3 &v) {
	static unsigned long int arrowID = 0;

	SceneObject object{"Arrow" + std::to_string(arrowID++)};
	object.set<CollisionComponent>();

	auto &movementComponent = object.set<MovementComponent>(new EasyMovement([v] (SceneObject &object) {
		object.get<MovementComponent>().v = v;
	}));

	// FIXME: LIFETIME COMPONENT

	movementComponent.speed = 0.3f;
	movementComponent.behaviour.reset(new EasyBehaviour([] (SceneObject &object) {
		object.get<SceneNodeComponent>().node->pitch(Ogre::Degree(90));
		object.get<SceneNodeComponent>().node->roll(Ogre::Degree(270));
	}));

	auto &bodyNodeComponent = object.set<SceneNodeComponent>(pos, Ogre::Vector3(0.12, 0.12, 0.12));
	auto &entityListComponent = object.set<EntityListComponent>(bodyNodeComponent.node);
	entityListComponent.addEntity(object.name() + "Body", "Arrow.mesh", true);

	return object;
}

