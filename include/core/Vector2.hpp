/*
 * =====================================================================================
 *
 *       Filename:  Vector2.hpp
 *
 *    Description:
 *
 *        Created:  20/04/2017 23:16:23
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef VECTOR2_HPP_
#define VECTOR2_HPP_

#include <stdexcept>
#include <utility>

#include "IntTypes.hpp"

template<typename T>
class Vector2 {
	public:
		Vector2() = default;

		Vector2(const T _x, const T _y) : x(_x), y(_y) {}

		template<typename U>
		Vector2(const Vector2<U> &vector2) : x(vector2.x), y(vector2.y) {}

		Vector2 operator+(const Vector2<T> &vector2) const { return Vector2{x + vector2.x, y + vector2.y}; }
		Vector2 operator-(const Vector2<T> &vector2) const { return Vector2{x - vector2.x, y - vector2.y}; }
		Vector2 operator*(const T n)                 const { return Vector2{x * n, y * n}; }

		Vector2 operator/(const T n) const {
			if(n != 0) {
				return Vector2{x / n, y / n};
			} else {
				throw std::overflow_error("Divide by zero exception");
			}
		}

		Vector2 &operator=(const T n)               { x = n; y = n; return *this; }
		Vector2 &operator+=(const Vector2 &vector2) { *this = operator+(vector2); return *this; }
		Vector2 &operator-=(const Vector2 &vector2) { *this = operator-(vector2); return *this; }
		Vector2 &operator*=(const T n)              { *this = operator*(n); return *this; }
		Vector2 &operator/=(const T n)              { *this = operator/(n); return *this; }

		bool operator==(const Vector2<T> &vector2) const { return x == vector2.x && y == vector2.y; }
		bool operator!=(const Vector2<T> &vector2) const { return !operator==(vector2); }

		// Needed if Vector2 is used as a key in a std::map
		bool operator<(const Vector2<T> &vector2) const { return x < vector2.x && y <= vector2.y; }
		bool operator>(const Vector2<T> &vector2) const { return x > vector2.x && y >= vector2.y; }

		T x;
		T y;
};

template<typename T>
Vector2<T> operator*(const T n, const Vector2<T> &vector2) { return vector2.operator*(n); }

using Vector2i = Vector2<int>;
using Vector2u = Vector2<unsigned int>;
using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;

#endif // VECTOR2_HPP_

