/*
 * =====================================================================================
 *
 *       Filename:  SinbadFactory.cpp
 *
 *    Description:
 *
 *        Created:  28/05/2017 13:22:44
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <Ogre.h>

#include "AnimationListComponent.hpp"
#include "CollisionComponent.hpp"
#include "EntityListComponent.hpp"
#include "GamePadMovement.hpp"
#include "MovementComponent.hpp"
#include "OgreData.hpp"
#include "PositionComponent.hpp"
#include "SceneNodeComponent.hpp"
#include "SinbadFactory.hpp"

SceneObject SinbadFactory::create() {
	SceneObject object("Sinbad");

	auto &bodyNodeComponent = object.set<SceneNodeComponent>(Ogre::Vector3(10, CHAR_HEIGHT, 10), Ogre::Vector3(0.5, 0.5, 0.5));
	auto &entityListComponent = object.set<EntityListComponent>(bodyNodeComponent.node);

	object.set<MovementComponent>(MovementComponent(new GamePadMovement));
	object.set<CollisionComponent>(CollisionComponent());

	Ogre::Entity *bodyEntity = entityListComponent.addEntity("SinbadBody_", "Sinbad.mesh", true);
	bodyEntity->getSkeleton()->setBlendMode(Ogre::ANIMBLEND_CUMULATIVE);

	entityListComponent.addEntity("SinbadSword1_", "Sword.mesh");
	entityListComponent.addEntity("SinbadSword2_", "Sword.mesh");
	entityListComponent.linkEntityToBone("SinbadSword1_", "SinbadBody_", "Sheath.L");
	entityListComponent.linkEntityToBone("SinbadSword2_", "SinbadBody_", "Sheath.R");

	const char *animNames[] = {
		"IdleBase", "IdleTop", "RunBase", "RunTop", "HandsClosed", "HandsRelaxed", "DrawSwords",
		"SliceVertical", "SliceHorizontal", "Dance", "JumpStart", "JumpLoop", "JumpEnd"
	};

	auto &animationListComponent = object.set<AnimationListComponent>();
	for (const char *animName : animNames) {
		animationListComponent.add(bodyEntity, animName);
	}

	animationListComponent.enableAnimation("HandsRelaxed");
	animationListComponent.setActiveAnimation(0, "IdleTop");
	animationListComponent.setActiveAnimation(1, "IdleBase");

	return object;
}

