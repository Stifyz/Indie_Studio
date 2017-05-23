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
#include "Rect.hpp"
#include "Vector2.hpp"

class PositionComponent : public FloatRect {
	public:
		PositionComponent() = default;

		PositionComponent(float x, float y, float width, float height, Direction _direction = Direction::None)
			: FloatRect(x, y, width, height), direction(_direction) {
		}

		PositionComponent(const Vector2f &position, const Vector2f &size)
			: FloatRect(position, size) {
		}

		void updateDirection(const Vector2f &v) {
			if(v.x < 0) direction = Direction::Left;
			if(v.x > 0) direction = Direction::Right;
			if(v.y < 0) direction = Direction::Up;
			if(v.y > 0) direction = Direction::Down;
		}

		Direction direction = Direction::None;
};

#endif // POSITIONCOMPONENT_HPP_
