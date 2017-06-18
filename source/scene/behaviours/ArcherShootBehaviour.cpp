/*
 * =====================================================================================
 *
 *       Filename:  ArcherShootBehaviour.cpp
 *
 *    Description:
 *
 *        Created:  16/06/2017 08:47:10
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <OgreBone.h>
#include <OgreSkeletonInstance.h>

#include "ArrowFactory.hpp"
#include "ArcherShootBehaviour.hpp"
#include "EntityListComponent.hpp"
#include "SceneNodeComponent.hpp"
#include "SceneObjectList.hpp"

void ArcherShootBehaviour::action(SceneObject &object) {
	auto &sceneNodeComponent = object.get<SceneNodeComponent>();
	auto &sceneObjectList = object.get<SceneObjectList>();

	Ogre::Entity *entity = object.get<EntityListComponent>().getEntity(object.name() + "Body");
	Ogre::AxisAlignedBox box = entity->getWorldBoundingBox();
	Ogre::Vector3 pos = box.getMinimum() + (box.getMaximum() - box.getMinimum()) / 2.0f;

	const Ogre::Quaternion &orientation = sceneNodeComponent.node->getOrientation();
	int yaw = orientation.getYaw().valueDegrees();

	Ogre::Vector3 direction(0, 0, 0);
	direction.x = (yaw < 0) ? -1 : ((yaw > 0 && yaw < 180) ? 1 : 0);
	direction.z = (abs(yaw) > 90) ? -1 : ((abs(yaw) < 90) ? 1 : 0);

	pos = pos * Ogre::Vector3::UNIT_Y + sceneNodeComponent.root->getPosition() + entity->getSkeleton()->getBone("string_ctrl")->getPosition();
	sceneObjectList.addObject(ArrowFactory::create(pos, direction));

	AudioPlayer::playEffect("attack_archer1");
}

