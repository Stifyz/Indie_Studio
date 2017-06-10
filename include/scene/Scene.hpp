/*
 * =====================================================================================
 *
 *       Filename:  Scene.hpp
 *
 *    Description:
 *
 *        Created:  20/04/2017 21:56:41
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <functional>

#include "SceneObject.hpp"
#include "SceneObjectList.hpp"

class Scene {
	public:
		void reset();
		void update();

		SceneObject &addObject(SceneObject &&object);

		void addCollisionChecker(std::function<void(SceneObject &)> checker);
		void checkCollisionsFor(SceneObject &object);

		const SceneObjectList &objects() const { return m_objects; }

	private:
		SceneObjectList m_objects;
};

#endif // SCENE_HPP_
