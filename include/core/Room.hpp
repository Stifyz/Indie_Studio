/*
 * =====================================================================================
 *
 *       Filename:  Room.hpp
 *
 *    Description:
 *
 *        Created:  26/05/2017 14:02:31
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ROOM_HPP_
#define ROOM_HPP_

#include <deque>
#include <vector>

#include <OgreEntity.h>

#include "IntTypes.hpp"
#include "SceneObject.hpp"

class Room {
	public:
		Room(const u16 width, const u16 height, std::vector<u16> &&data);

		void init();

		void checkCollisions(SceneObject &object);

	private:
		const u16 m_width;
		const u16 m_height;

		std::vector<u16> m_data;

		std::deque<Ogre::Entity *> m_walls;
};

#endif // ROOM_HPP_
