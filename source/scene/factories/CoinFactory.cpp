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
#include "CoinFactory.hpp"
#include "CollisionComponent.hpp"
#include "EasyBehaviour.hpp"
#include "EntityListComponent.hpp"
#include "LifetimeComponent.hpp"
#include "SceneNodeComponent.hpp"
#include "ScoreComponent.hpp"

static unsigned long int coinCount = 0;

SceneObject CoinFactory::create(const Ogre::Vector3 &pos) {
	SceneObject object{"Coin" + std::to_string(coinCount++)};
	object.set<CollisionComponent>().addAction(&CoinFactory::coinAction);
	object.set<LifetimeComponent>();

	auto &bodyNodeComponent = object.set<SceneNodeComponent>(pos, Ogre::Vector3(3, 3, 3));
	bodyNodeComponent.node->pitch(Ogre::Degree(90));

	auto &entityListComponent = object.set<EntityListComponent>(bodyNodeComponent.node);
	entityListComponent.addEntity(object.name() + "Body", "coin.001.mesh", true);

	auto &behaviourComponent = object.set<BehaviourComponent>();
	behaviourComponent.addBehaviour<EasyBehaviour>("Animation", [] (SceneObject &object) {
		object.get<SceneNodeComponent>().node->roll(Ogre::Degree(0.2));
	});

	return object;
}

void CoinFactory::coinAction(SceneObject &coin, SceneObject &object, const CollisionInfo &info) {
	if (info.inCollision && object.type() == "Player" && !coin.get<LifetimeComponent>().dead(coin)) {
		object.get<ScoreComponent>().gold += 500;
		coin.get<LifetimeComponent>().kill();

		AudioPlayer::playEffect("gold1");
	}
}


