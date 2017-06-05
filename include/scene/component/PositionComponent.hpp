/*
 * =====================================================================================
 *
 *       Filename:  PositionComponent.hpp
 *
 *    Description:
 *
 *        Created:  20/04/2017 23:12:36
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef POSITIONCOMPONENT_HPP_
#define POSITIONCOMPONENT_HPP_

#include "Direction.hpp"
// #include "Rect.hpp"
#include <OgreAxisAlignedBox.h>

class PositionComponent : public Ogre::AxisAlignedBox {
	public:
		PositionComponent() = default;

		PositionComponent(const float x, const float y, const float z,
				const float width, const float height, const float depth,
				Direction _direction = Direction::None)
			: Ogre::AxisAlignedBox(x, y, z, x + width, y + height, z + depth), direction(_direction) {
		}

		PositionComponent(const Ogre::Vector3 &position, const Ogre::Vector3 &size)
			: Ogre::AxisAlignedBox(position, {position.x + size.x, position.y + size.y, position.z + size.z}) {}

		void updateDirection(const Ogre::Vector3 &v) {
			if(v.x < 0) direction = Direction::Left;
			if(v.x > 0) direction = Direction::Right;
			if(v.y < 0) direction = Direction::Up;
			if(v.y > 0) direction = Direction::Down;
		}

		Direction direction = Direction::None;
};

#endif // POSITIONCOMPONENT_HPP_
