/*
 * =====================================================================================
 *
 *       Filename:  Room.cpp
 *
 *    Description:
 *
 *        Created:  26/05/2017 14:02:53
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <iostream>

#include <Ogre.h>

#include "EntityListComponent.hpp"
#include "MovementComponent.hpp"
#include "Room.hpp"

Room::Room(const u16 width, const u16 height, std::vector<u16> &&data) : m_width(width), m_height(height) {
	m_data = std::forward<decltype(data)>(data);
}

void Room::init(Ogre::SceneManager *sceneManager) {
	const unsigned int tileSize = 10;

	for (u16 y = 0 ; y < m_height ; ++y) {
		for (u16 x = 0 ; x < m_width ; ++x) {
			if (m_data[x + y * m_width]) {
				std::string meshID("00000000");

				meshID[6] = (                    y > 0             && m_data[x     + (y - 1) * m_width]) ? '1' : '0';
				meshID[4] = (x < m_width - 1                       && m_data[x + 1 + y       * m_width]) ? '1' : '0';
				meshID[2] = (                    y < m_height - 1  && m_data[x     + (y + 1) * m_width]) ? '1' : '0';
				meshID[0] = (x > 0                                 && m_data[x - 1 + y       * m_width]) ? '1' : '0';

				if (meshID[6] == '1' && meshID[0] == '1') {
					meshID[7] = (x > 0           && y > 0            && m_data[x - 1 + (y - 1) * m_width]) ? '1' : '0';
				}
				if (meshID[4] == '1' && meshID[6] == '1') {
					meshID[5] = (x < m_width - 1 && y > 0            && m_data[x + 1 + (y - 1) * m_width]) ? '1' : '0';
				}
				if (meshID[2] == '1' && meshID[4] == '1') {
					meshID[3] = (x < m_width - 1 && y < m_height - 1 && m_data[x + 1 + (y + 1) * m_width]) ? '1' : '0';
				}
				if (meshID[0] == '1' && meshID[2] == '1') {
					meshID[1] = (x > 0           && y < m_height - 1 && m_data[x - 1 + (y + 1) * m_width]) ? '1' : '0';
				}

				Ogre::Entity* ent = sceneManager->createEntity("Claimed_" + meshID + ".mesh");
				ent->setMaterialName("Claimed");
				// ent->setMaterialName("Test");
				m_walls.emplace_back(ent);

				Ogre::SceneNode* node = sceneManager->getRootSceneNode()->createChildSceneNode();
				node->setScale(4, 4, 4);
				node->setPosition(tileSize * x, 0.001, tileSize * y);
				node->attachObject(ent);
			}
		}
	}

	Ogre::Light* light = sceneManager->createLight("RoomLight");
	light->setType(Ogre::Light::LT_POINT);
	light->setPosition(m_width * tileSize / 2, 60, m_height * tileSize / 2);
	light->setSpecularColour(Ogre::ColourValue::White);

	Ogre::MeshManager::getSingleton().createPlane("floor", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
			Ogre::Plane(Ogre::Vector3::UNIT_Y, 0), m_width * tileSize, m_height * tileSize, 10, 10, true, 1, 10, 10, Ogre::Vector3::UNIT_Z);

	Ogre::Entity* floor = sceneManager->createEntity("Floor", "floor");
	floor->setMaterialName("Examples/Rockwall");
	floor->setCastShadows(false);

	Ogre::SceneNode* floorNode = sceneManager->getRootSceneNode()->createChildSceneNode();
	floorNode->setPosition(m_width * tileSize / 2.0 - tileSize / 2.0, 0, m_height * tileSize / 2.0 - tileSize / 2.0);
	floorNode->attachObject(floor);
}

void Room::checkCollisions(SceneObject &object) {
	Ogre::Entity *entity = object.get<EntityListComponent>().getEntity(object.name() + "Body");
	if(entity && object.has<MovementComponent>()) {
		for (Ogre::Entity *wall : m_walls) {
			Ogre::AxisAlignedBox wallHitbox = wall->getWorldBoundingBox();
			Ogre::AxisAlignedBox entityHitbox = entity->getWorldBoundingBox();

			std::cout << entityHitbox << std::endl;

			auto &v = object.get<MovementComponent>().v;
			entityHitbox.getMinimum() += v * Ogre::Vector3::UNIT_X;
			entityHitbox.getMaximum() += v * Ogre::Vector3::UNIT_X;

			if (entityHitbox.intersects(wallHitbox)) {
				object.get<MovementComponent>().v.x = 0;
			}

			entityHitbox = entity->getWorldBoundingBox();

			entityHitbox.getMinimum() += v * Ogre::Vector3::UNIT_Z;
			entityHitbox.getMaximum() += v * Ogre::Vector3::UNIT_Z;

			if (entityHitbox.intersects(wallHitbox)) {
				object.get<MovementComponent>().v.z = 0;
			}
		}
	}
}

