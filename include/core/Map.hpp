/*
 * =====================================================================================
 *
 *       Filename:  Map.hpp
 *
 *    Description:
 *
 *        Created:  26/05/2017 14:02:31
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAP_HPP_
#define MAP_HPP_

#include <deque>
#include <vector>

#include <OgreEntity.h>

#include "MapTile.hpp"
#include "Scene.hpp"

class Map {
	public:
		Map(const u16 width, const u16 height, std::vector<MapTile> &&data);

		void init(Scene &scene);

		void checkCollisions(SceneObject &object);

	private:
		const u16 m_width;
		const u16 m_height;

		std::vector<MapTile> m_data;

		std::deque<Ogre::Entity *> m_walls;
};

#endif // MAP_HPP_
