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
#include <OgreSkeletonInstance.h>

#include "AnimationListComponent.hpp"
#include "CollisionComponent.hpp"
#include "EntityListComponent.hpp"
#include "GamePadMovement.hpp"
#include "MovementComponent.hpp"
#include "SceneNodeComponent.hpp"
#include "SinbadFactory.hpp"

SceneObject SinbadFactory::create() {
	SceneObject object("Sinbad");
	object.set<CollisionComponent>();

	auto &bodyNodeComponent = object.set<SceneNodeComponent>(Ogre::Vector3(20, CHAR_HEIGHT, 20), Ogre::Vector3(0.5, 0.5, 0.5));
	auto &entityListComponent = object.set<EntityListComponent>(bodyNodeComponent.node);
	bodyNodeComponent.node->setFixedYawAxis(true);

	auto &movementComponent = object.set<MovementComponent>(new GamePadMovement);
	movementComponent.behaviour = &SinbadFactory::movementBehaviour;

	Ogre::Entity *bodyEntity = entityListComponent.addEntity("SinbadBody", "Sinbad.mesh", true);
	bodyEntity->getSkeleton()->setBlendMode(Ogre::ANIMBLEND_CUMULATIVE);

	entityListComponent.addEntity("SinbadSword1_", "Sword.mesh");
	entityListComponent.addEntity("SinbadSword2_", "Sword.mesh");
	entityListComponent.linkEntityToBone("SinbadSword1_", "SinbadBody", "Sheath.L");
	entityListComponent.linkEntityToBone("SinbadSword2_", "SinbadBody", "Sheath.R");

	const char *animNames[] = {
		"IdleBase", "IdleTop", "RunBase", "RunTop", "HandsClosed", "HandsRelaxed", "DrawSwords",
		"SliceVertical", "SliceHorizontal", "Dance", "JumpStart", "JumpLoop", "JumpEnd"
	};

	auto &animationListComponent = object.set<AnimationListComponent>();
	for (const char *animName : animNames) {
		animationListComponent.add(bodyEntity, animName);
	}

	animationListComponent.enableAnimation("HandsRelaxed");
	animationListComponent.setActiveAnimation(0, "Dance");
	// animationListComponent.setActiveAnimation(1, "IdleBase");

	return object;
}

void SinbadFactory::movementBehaviour(SceneObject &object) {
	updateAnimation(object);
	// updateDirection(object);
}

void SinbadFactory::updateAnimation(SceneObject &object) {
	auto &movementComponent = object.get<MovementComponent>();
	auto &animationListComponent = object.get<AnimationListComponent>();

	static bool oldMovingState = false;
	if (oldMovingState != movementComponent.isMoving) {
		if (movementComponent.isMoving) {
			animationListComponent.setActiveAnimation(0, "RunTop");
			animationListComponent.setActiveAnimation(1, "RunBase");
		}
		else {
			animationListComponent.setActiveAnimation(0, "Dance");
			animationListComponent.setActiveAnimation(1, nullptr);
		}
	}

	oldMovingState = movementComponent.isMoving;
}

void SinbadFactory::updateDirection(SceneObject &object) {
	OgreBites::TrayManager *trayManager = OgreData::getInstance().trayManager();
	Ogre::Ray ray = trayManager->getCursorRay(object.get<Ogre::Camera *>());
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, CHAR_HEIGHT / 2);

	std::pair<bool, float> intersection = ray.intersects(plane);
	if (intersection.first) {
		Ogre::Vector3 point = ray.getPoint(intersection.second);

		Ogre::SceneNode *root = object.get<SceneNodeComponent>().root;
		Ogre::SceneNode *node = object.get<SceneNodeComponent>().node;
		node->resetOrientation();
		node->setDirection(root->getPosition() - point);
	}
}

