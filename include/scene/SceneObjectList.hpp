/*
 * =====================================================================================
 *
 *       Filename:  SceneObjectList.hpp
 *
 *    Description:
 *
 *        Created:  20/04/2017 22:38:59
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCENEOBJECTLIST_HPP_
#define SCENEOBJECTLIST_HPP_

#include <deque>

#include "SceneObject.hpp"

class SceneObjectList {
	using iterator = std::deque<SceneObject>::iterator;
	using const_iterator = std::deque<SceneObject>::const_iterator;

	public:
		SceneObject &addObject(SceneObject &&object, bool addToBack = true) {
			if (addToBack) {
				m_objects.emplace_back(std::move(object));
				return m_objects.back();
			}
			else {
				m_objects.emplace_front(std::move(object));
				return m_objects.front();
			}
		}

		void pop() { m_objects.pop_back(); }

		SceneObject &operator[](size_t n) { return m_objects[n]; }

		void remove(size_t n) { m_objects.erase(m_objects.begin() + n); }

		iterator begin() noexcept { return m_objects.begin(); }
		iterator end() noexcept { return m_objects.end(); }

		const_iterator begin() const noexcept { return m_objects.begin(); }
		const_iterator end() const noexcept { return m_objects.end(); }

		size_t size() const { return m_objects.size(); }

	private:
		std::deque<SceneObject> m_objects;
};

#endif // SCENEOBJECTLIST_HPP_
