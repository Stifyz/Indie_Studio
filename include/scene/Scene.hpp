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

#include "SceneObject.hpp"
#include "SceneObjectList.hpp"

class Scene {
	public:
		void reset();
		void update();

		SceneObject &addObject(SceneObject &&object);

		void checkCollisionsFor(SceneObject &object);

		static bool isPlayer(const SceneObject &object) { return player == &object; }
		static SceneObject *player;

		const SceneObjectList &objects() const { return m_objects; }

	private:
		SceneObjectList m_objects;
};

#endif // SCENE_HPP_
