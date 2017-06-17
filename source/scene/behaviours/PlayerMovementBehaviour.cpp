/*
 * =====================================================================================
 *
 *       Filename:  PlayerMovementBehaviour.cpp
 *
 *    Description:
 *
 *        Created:  16/06/2017 07:39:20
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "AnimationListComponent.hpp"
#include "EntityListComponent.hpp"
#include "MovementComponent.hpp"
#include "PlayerMovementBehaviour.hpp"
#include "SceneNodeComponent.hpp"

PlayerMovementBehaviour::PlayerMovementBehaviour(AnimList &&idleAnimations, AnimList &&walkAnimations)
	: m_idleAnimations(std::forward<AnimList>(idleAnimations)),
	  m_walkAnimations(std::forward<AnimList>(walkAnimations))
{
}

void PlayerMovementBehaviour::update(SceneObject &object) {
	updateAnimation(object);
	// updateDirection(object);
}

void PlayerMovementBehaviour::updateAnimation(SceneObject &object) {
	auto &movementComponent = object.get<MovementComponent>();
	auto &animationListComponent = object.get<AnimationListComponent>();

	if (m_oldMovingState != movementComponent.isMoving) {
		const AnimList &activeAnimList = (movementComponent.isMoving) ? m_walkAnimations : m_idleAnimations;
		const AnimList &inactiveAnimList = (!movementComponent.isMoving) ? m_walkAnimations : m_idleAnimations;

		unsigned int editedAnims = 0;
		for (unsigned int i = 0 ; i < activeAnimList.size() ; ++i) {
			const char *activeAnimation = animationListComponent.getActiveAnimation(i);
			if (activeAnimation && std::string(activeAnimation) == inactiveAnimList[i]) {
				animationListComponent.setActiveAnimation(i, activeAnimList[i]);
				++editedAnims;
			}
		}

		if (editedAnims)
			m_oldMovingState = movementComponent.isMoving;
	}
}

void PlayerMovementBehaviour::updateDirection(SceneObject &object) {
	Ogre::Entity *bodyEntity = object.get<EntityListComponent>().getEntity(object.name() + "Body");
	Ogre::AxisAlignedBox bodyEntityBoundingBox = bodyEntity->getBoundingBox();

	OgreBites::TrayManager *trayManager = OgreData::getInstance().trayManager();
	Ogre::Ray ray = trayManager->getCursorRay(object.get<Ogre::Camera *>());
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, bodyEntityBoundingBox.getMaximum().y / 2.0f);

	std::pair<bool, float> intersection = ray.intersects(plane);
	if (intersection.first) {
		Ogre::Vector3 point = ray.getPoint(intersection.second);

		Ogre::SceneNode *node = object.get<SceneNodeComponent>().node;
		node->resetOrientation();
		node->setDirection(object.get<SceneNodeComponent>().root->getPosition() - point);
	}
}

