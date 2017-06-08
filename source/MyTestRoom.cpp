/*
 * =====================================================================================
 *
 *       Filename:  MyTestRoom.cpp
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

#include "MyTestRoom.hpp"

void MyTestRoom::init(Ogre::SceneManager *sceneManager) {
	const unsigned int mapWidth = 9;
	const unsigned int mapHeight = 7;
	const unsigned int tileSize = 10;

	const std::array<char, mapWidth * mapHeight> mapData = {
		0, 0, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 0, 1,
		0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1,
	};

	for (unsigned int y = 0 ; y <  mapHeight ; ++y) {
		for (unsigned int x = 0 ; x < mapWidth ; ++x) {
			if (mapData[x + y * mapWidth]) {
				std::string meshID("00000000");

				meshID[6] = (                    y > 0             && mapData[x     + (y - 1) * mapWidth]) ? '1' : '0';
				meshID[4] = (x < mapWidth - 1                      && mapData[x + 1 + y       * mapWidth]) ? '1' : '0';
				meshID[2] = (                    y < mapHeight - 1 && mapData[x     + (y + 1) * mapWidth]) ? '1' : '0';
				meshID[0] = (x > 0                                 && mapData[x - 1 + y       * mapWidth]) ? '1' : '0';

				if (meshID[6] == '1' && meshID[0] == '1') {
					meshID[7] = (x > 0            && y > 0             && mapData[x - 1 + (y - 1) * mapWidth]) ? '1' : '0';
				}
				if (meshID[4] == '1' && meshID[6] == '1') {
					meshID[5] = (x < mapWidth - 1 && y > 0             && mapData[x + 1 + (y - 1) * mapWidth]) ? '1' : '0';
				}
				if (meshID[2] == '1' && meshID[4] == '1') {
					meshID[3] = (x < mapWidth - 1 && y < mapHeight - 1 && mapData[x + 1 + (y + 1) * mapWidth]) ? '1' : '0';
				}
				if (meshID[0] == '1' && meshID[2] == '1') {
					meshID[1] = (x > 0            && y < mapHeight - 1 && mapData[x - 1 + (y + 1) * mapWidth]) ? '1' : '0';
				}

				Ogre::Entity* ent = sceneManager->createEntity("Claimed_" + meshID + ".mesh");
				ent->setMaterialName("Claimed");
				// ent->setMaterialName("Test");

				Ogre::SceneNode* node = sceneManager->getRootSceneNode()->createChildSceneNode();
				node->setScale(4, 4, 4);
				node->setPosition(tileSize * x, 0.001, tileSize * y);
				node->attachObject(ent);
			}
		}
	}

	Ogre::Light* light = sceneManager->createLight("RoomLight");
	light->setType(Ogre::Light::LT_POINT);
	light->setPosition(mapWidth * tileSize / 2, 60, mapHeight * tileSize / 2);
	light->setSpecularColour(Ogre::ColourValue::White);

	Ogre::MeshManager::getSingleton().createPlane("floor", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
			Ogre::Plane(Ogre::Vector3::UNIT_Y, 0), mapWidth * tileSize, mapHeight * tileSize, 10, 10, true, 1, 10, 10, Ogre::Vector3::UNIT_Z);

	Ogre::Entity* floor = sceneManager->createEntity("Floor", "floor");
	floor->setMaterialName("Examples/Rockwall");
	floor->setCastShadows(false);

	Ogre::SceneNode* floorNode = sceneManager->getRootSceneNode()->createChildSceneNode();
	floorNode->setPosition(mapWidth * tileSize / 2.0 - tileSize / 2.0, 0, mapHeight * tileSize / 2.0 - tileSize / 2.0);
	floorNode->attachObject(floor);
}

