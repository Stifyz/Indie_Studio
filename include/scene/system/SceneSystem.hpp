/*
 * =====================================================================================
 *
 *       Filename:  SceneSystem.hpp
 *
 *    Description:
 *
 *        Created:  20/04/2017 22:51:19
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCENESYSTEM_HPP_
#define SCENESYSTEM_HPP_

#include "SceneObject.hpp"
#include "SceneObjectList.hpp"

class SceneSystem {
	public:
		static void reset(SceneObjectList &objectList);
		static void update(SceneObjectList &objectList);
		static void draw(SceneObjectList &objectList);

		static void resetObject(SceneObject &object);
		static void updateObject(SceneObject &object);
		static void drawObject(SceneObject &object);
};

#endif // SCENESYSTEM_HPP_
