/*
 * =====================================================================================
 *
 *       Filename:  KeyFactory.cpp
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
#include "KeyFactory.hpp"
#include "SceneNodeComponent.hpp"

SceneObject KeyFactory::create(const Ogre::Vector3 &pos) {
	SceneObject object{"Key"};
	object.set<CollisionComponent>();

	auto &bodyNodeComponent = object.set<SceneNodeComponent>(pos, Ogre::Vector3(3, 3, 3));
       	bodyNodeComponent.node->pitch(Ogre::Degree(90));

	auto &entityListComponent = object.set<EntityListComponent>(bodyNodeComponent.node);
	entityListComponent.addEntity("KeyBody", "Key.mesh", true);

	auto &behaviourComponent = object.set<BehaviourComponent>();
	behaviourComponent.addBehaviour<EasyBehaviour>("Animation", [] (SceneObject &object) {
      	object.get<SceneNodeComponent>().node->roll(Ogre::Degree(0.2));
	});

	return object;
}

