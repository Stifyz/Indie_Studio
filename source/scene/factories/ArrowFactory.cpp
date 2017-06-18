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
#include "AnimationListComponent.hpp"
#include "ArrowFactory.hpp"
#include "AudioPlayer.hpp"
#include "CollisionComponent.hpp"
#include "EasyBehaviour.hpp"
#include "EasyMovement.hpp"
#include "EntityListComponent.hpp"
#include "HealthComponent.hpp"
#include "LifetimeComponent.hpp"
#include "MovementComponent.hpp"
#include "SceneNodeComponent.hpp"

static unsigned long int arrowCount = 0;

SceneObject ArrowFactory::create(const Ogre::Vector3 &pos, const Ogre::Vector3 &v) {
	SceneObject object{"Arrow" + std::to_string(arrowCount++)};
	object.set<CollisionComponent>().addAction(&ArrowFactory::arrowAction);
	object.set<LifetimeComponent>(500);

	auto &movementComponent = object.set<MovementComponent>(new EasyMovement([v] (SceneObject &object) {
		object.get<MovementComponent>().v = v;
	}));

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

void ArrowFactory::arrowAction(SceneObject &arrow, SceneObject &object, const CollisionInfo &info) {
	if (info.inCollision) {
		if (object.type() == "Enemy" && !object.get<LifetimeComponent>().dead(object)) {
			auto &healthComponent = object.get<HealthComponent>();
			healthComponent.removeLife(25);

			if (healthComponent.life() == 0) {
				AudioPlayer::playEffect("vocal_monster2");
				if (object.has<AnimationListComponent>())
					object.get<AnimationListComponent>().setActiveAnimation(0, "Die", true)->timer.setTime(6);
				object.remove<MovementComponent>();
			}
			else if (object.has<AnimationListComponent>() && object.get<AnimationListComponent>().isAnimationFinished("Hit")) {
				object.get<AnimationListComponent>().setActiveAnimation(0, "Hit", true)->timer.setTime(6);
			}
		}

		if ((object.type() == "Enemy" && object.get<HealthComponent>().life()) || object.name() == "Wall")
			arrow.get<LifetimeComponent>().kill();
	}
}

