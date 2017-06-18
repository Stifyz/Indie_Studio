/*
 * =====================================================================================
 *
 *       Filename:  Map.cpp
 *
 *    Description:
 *
 *        Created:  26/05/2017 14:02:53
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <Ogre.h>

#include "CollisionComponent.hpp"
#include "EntityListComponent.hpp"
#include "MovementComponent.hpp"
#include "OgreData.hpp"
#include "Map.hpp"

#include "CelticCrossFactory.hpp"
#include "CoinFactory.hpp"
#include "HeartFactory.hpp"
#include "SpawnerFactory.hpp"
#include "TorchFactory.hpp"

Map::Map(const u16 width, const u16 height, std::vector<MapTile> &&data) : m_width(width), m_height(height) {
	m_data = std::forward<decltype(data)>(data);
}

void Map::init(Scene &scene) {
	Ogre::SceneManager *sceneManager = OgreData::getInstance().sceneManager();
	const float tileSize = 10;

	for (u16 y = 0 ; y < m_height ; ++y) {
		for (u16 x = 0 ; x < m_width ; ++x) {
			if (m_data[x + y * m_width] == MapTile::Wall) {
				std::string meshID("00000000");

				meshID[6] = (                    y > 0             && m_data[x     + (y - 1) * m_width] == MapTile::Wall) ? '1' : '0';
				meshID[4] = (x < m_width - 1                       && m_data[x + 1 + y       * m_width] == MapTile::Wall) ? '1' : '0';
				meshID[2] = (                    y < m_height - 1  && m_data[x     + (y + 1) * m_width] == MapTile::Wall) ? '1' : '0';
				meshID[0] = (x > 0                                 && m_data[x - 1 + y       * m_width] == MapTile::Wall) ? '1' : '0';

				if (meshID[6] == '1' && meshID[0] == '1') {
					meshID[7] = (x > 0           && y > 0            && m_data[x - 1 + (y - 1) * m_width] == MapTile::Wall) ? '1' : '0';
				}
				if (meshID[4] == '1' && meshID[6] == '1') {
					meshID[5] = (x < m_width - 1 && y > 0            && m_data[x + 1 + (y - 1) * m_width] == MapTile::Wall) ? '1' : '0';
				}
				if (meshID[2] == '1' && meshID[4] == '1') {
					meshID[3] = (x < m_width - 1 && y < m_height - 1 && m_data[x + 1 + (y + 1) * m_width] == MapTile::Wall) ? '1' : '0';
				}
				if (meshID[0] == '1' && meshID[2] == '1') {
					meshID[1] = (x > 0           && y < m_height - 1 && m_data[x - 1 + (y + 1) * m_width] == MapTile::Wall) ? '1' : '0';
				}

				// Ogre::MeshPtr pMesh = Ogre::MeshManager::getSingleton().load("Claimed_" + meshID + ".mesh",
				//                                                              Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
				//                                                              Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY,
				//                                                              Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY,
				//                                                              true, true);
                //
				// unsigned short src, dest;
				// if (!pMesh->suggestTangentVectorBuildParams(Ogre::VES_TANGENT, src, dest)) {
				// 	pMesh->buildTangentVectors(Ogre::VES_TANGENT, src, dest);
				// }

				Ogre::Entity* ent = sceneManager->createEntity("Claimed_" + meshID + ".mesh");

				// Ogre::Entity* ent;
				// try {
				// 	ent = sceneManager->createEntity("Dirt_" + meshID + ".mesh");
				// }
				// catch (...) {
				// 	ent = sceneManager->createEntity("Dirt_" + meshID + "a" + ".mesh");
				// }

				// Ogre::Entity* ent = sceneManager->createEntity(pMesh);
				// ent->setMaterialName("Claimed");
				ent->setMaterialName("Test2");
				m_walls.emplace_back(ent);

				Ogre::SceneNode* node = sceneManager->getRootSceneNode()->createChildSceneNode();
				node->setScale(4, 4, 4);
				node->setPosition(tileSize * x, 0.001, tileSize * y);
				node->attachObject(ent);
			}
			else if (m_data[x + y * m_width] == MapTile::Heart) {
				scene.addObject(HeartFactory::create(Ogre::Vector3(x * tileSize, 1.5, y * tileSize)));
			}
			else if (m_data[x + y * m_width] == MapTile::Gold) {
				scene.addObject(CoinFactory::create(Ogre::Vector3(x * tileSize, 4, y * tileSize)));
			}
			else if (m_data[x + y * m_width] == MapTile::Spawner) {
				scene.addObject(SpawnerFactory::create(Ogre::Vector3(x * tileSize, 4, y * tileSize)));
			}
			else if (m_data[x + y * m_width] == MapTile::CelticCross) {
				scene.addObject(CelticCrossFactory::create(Ogre::Vector3(x * tileSize, 1.5, y * tileSize)));
			}
			// else if (m_data[x + y * m_width] == MapTile::Torch) {
			//   scene.addObject(TorchFactory::create(Ogre::Vector3(x * tileSize, 1.5, y * tileSize), Direction::Left));
			// }
		}
	}

	Ogre::Light* light = sceneManager->createLight("MapLight");
	light->setType(Ogre::Light::LT_POINT);
	light->setPosition((float)m_width * tileSize / 2.0, 60.0, (float)m_height * tileSize / 2.0);
	// light->setPosition(0.0, 60.0, 0.0);
	light->setSpecularColour(Ogre::ColourValue::White);
	light->setDiffuseColour(0.45, 0.45, 0.45);

	if (!Ogre::MeshManager::getSingleton().resourceExists("floor", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME))
		Ogre::MeshManager::getSingleton().createPlane("floor", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
			Ogre::Plane(Ogre::Vector3::UNIT_Y, 0), m_width * tileSize, m_height * tileSize, 10, 10, true, 1, 10, 10, Ogre::Vector3::UNIT_Z);

	Ogre::Entity* floor = sceneManager->createEntity("Floor", "floor");
	// floor->setMaterialName("rockwall");
	floor->setMaterialName("Claimed");
	floor->setCastShadows(false);

	Ogre::SceneNode* floorNode = sceneManager->getRootSceneNode()->createChildSceneNode();
	floorNode->setPosition(m_width * tileSize / 2.0 - tileSize / 2.0, 0, m_height * tileSize / 2.0 - tileSize / 2.0);
	floorNode->attachObject(floor);
}

void Map::checkCollisions(SceneObject &object) {
	Ogre::Entity *entity = object.get<EntityListComponent>().getEntity(object.name() + "Body");
	if(entity && object.has<MovementComponent>()) {
		for (Ogre::Entity *wall : m_walls) {
			Ogre::AxisAlignedBox wallHitbox = wall->getWorldBoundingBox();
			Ogre::Sphere entityHitbox = entity->getWorldBoundingSphere();
			entityHitbox.setRadius(entityHitbox.getRadius() / 3.0);

			SceneObject wallObj("Wall");

			auto &v = object.get<MovementComponent>().v;
			wallHitbox.getMinimum() -= v * Ogre::Vector3::UNIT_X;
			wallHitbox.getMaximum() -= v * Ogre::Vector3::UNIT_X;

			if (entityHitbox.intersects(wallHitbox)) {
				object.get<MovementComponent>().v.x = 0;
				object.get<CollisionComponent>().collisionActions(object, wallObj, CollisionInfo{true, "Body", "Wall"});
			}

			wallHitbox = wall->getWorldBoundingBox();

			wallHitbox.getMinimum() -= v * Ogre::Vector3::UNIT_Z;
			wallHitbox.getMaximum() -= v * Ogre::Vector3::UNIT_Z;

			if (entityHitbox.intersects(wallHitbox)) {
				object.get<MovementComponent>().v.z = 0;
				object.get<CollisionComponent>().collisionActions(object, wallObj, CollisionInfo{true, "Body", "Wall"});
			}
		}
	}
}

