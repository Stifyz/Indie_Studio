/*
 * =====================================================================================
 *
 *       Filename:  MapLoader.cpp
 *
 *    Description:
 *
 *        Created:  12/01/2015 15:05:28
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Map.hpp"
#include "MapLoader.hpp"
#include "MapTile.hpp"
#include "XMLFile.hpp"
// #include "SceneObjectLoader.hpp"

void MapLoader::load(const char *xmlFilename, ResourceHandler &handler) {
	XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *mapElement = doc.FirstChildElement("maps").FirstChildElement("map").ToElement();
	while(mapElement) {
		std::string name = mapElement->Attribute("name");

		DEBUG("Loading map", name + ".tmx");
		loadMap(name, handler);

		mapElement = mapElement->NextSiblingElement("map");
	}
}

void MapLoader::loadMap(const std::string &name, ResourceHandler &handler) {
	XMLFile doc("res/maps/" + name + ".tmx");

	tinyxml2::XMLElement *mapElement = doc.FirstChildElement("map").ToElement();

	u16 width = mapElement->IntAttribute("width");
	u16 height = mapElement->IntAttribute("height");

	std::vector<MapTile> data;
	tinyxml2::XMLElement *tileElement = mapElement->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
	while(tileElement) {
		s16 tileID = tileElement->IntAttribute("gid") - 1;

		data.push_back(static_cast<MapTile>((tileID >= 0) ? tileID : 0));

		tileElement = tileElement->NextSiblingElement("tile");
	}

	DEBUG(width * height, "tiles loaded");

	handler.add<Map>(name, width, height, std::move(data));

	// for(u16 tileY = 0 ; tileY < height ; tileY++) {
	// 	for(u16 tileX = 0 ; tileX < width ; tileX++) {
	// 		u16 tileID = map.getTile(tileX, tileY);
    //
	// 		if(tileset.info()[tileID] == TilesInfos::TileType::GrassTile) {
	// 			map.scene().addObject(GrassFactory::create(tileX, tileY));
	// 		}
	// 		else if(tileset.info()[tileID] == TilesInfos::TileType::LowGrassTile) {
	// 			map.scene().addObject(GrassFactory::create(tileX, tileY, true));
	// 		}
	// 	}
	// }
    //
	// SceneObjectLoader::load(name, map.scene());
}

