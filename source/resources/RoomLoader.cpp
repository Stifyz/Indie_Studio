/*
 * =====================================================================================
 *
 *       Filename:  RoomLoader.cpp
 *
 *    Description:
 *
 *        Created:  12/01/2015 15:05:28
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Room.hpp"
#include "RoomLoader.hpp"
#include "XMLFile.hpp"
// #include "SceneObjectLoader.hpp"

void RoomLoader::load(const char *xmlFilename, ResourceHandler &handler) {
	XMLFile doc(xmlFilename);

	XMLElement *roomElement = doc.FirstChildElement("rooms").FirstChildElement("room").ToElement();
	while(roomElement) {
		std::string name = roomElement->Attribute("name");

		DEBUG("Loading room", name + ".tmx");
		loadRoom(name, handler);

		roomElement = roomElement->NextSiblingElement("room");
	}
}

void RoomLoader::loadRoom(const std::string &name, ResourceHandler &handler) {
	XMLFile doc("res/rooms/" + name + ".tmx");

	XMLElement *roomElement = doc.FirstChildElement("map").ToElement();

	u16 width = roomElement->IntAttribute("width");
	u16 height = roomElement->IntAttribute("height");

	std::vector<u16> data;
	XMLElement *tileElement = roomElement->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
	while(tileElement) {
		s16 tileID = tileElement->IntAttribute("gid") - 1;

		data.push_back((tileID >= 0) ? tileID : 0);

		tileElement = tileElement->NextSiblingElement("tile");
	}

	DEBUG(width * height, "tiles loaded");

	handler.add<Room>(name, width, height, std::move(data));

	// for(u16 tileY = 0 ; tileY < height ; tileY++) {
	// 	for(u16 tileX = 0 ; tileX < width ; tileX++) {
	// 		u16 tileID = room.getTile(tileX, tileY);
    //
	// 		if(tileset.info()[tileID] == TilesInfos::TileType::GrassTile) {
	// 			room.scene().addObject(GrassFactory::create(tileX, tileY));
	// 		}
	// 		else if(tileset.info()[tileID] == TilesInfos::TileType::LowGrassTile) {
	// 			room.scene().addObject(GrassFactory::create(tileX, tileY, true));
	// 		}
	// 	}
	// }
    //
	// SceneObjectLoader::load(name, room.scene());
}

