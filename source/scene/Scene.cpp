/*
 * =====================================================================================
 *
 *       Filename:  Scene.cpp
 *
 *    Description:
 *
 *        Created:  20/04/2017 21:56:22
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "CollisionComponent.hpp"
#include "Scene.hpp"

#include "CollisionSystem.hpp"
#include "SceneSystem.hpp"

SceneObject *Scene::player = nullptr;

void Scene::reset() {
	SceneSystem::reset(m_objects);
}

void Scene::update() {
	SceneSystem::update(m_objects);

	if(player) SceneSystem::updateObject(*player);
}

void Scene::draw() {
	SceneSystem::draw(m_objects);

	if(player) SceneSystem::drawObject(*player);
}

SceneObject &Scene::addObject(SceneObject &&object) {
	SceneObject &obj = m_objects.addObject(std::move(object));

	if(obj.has<CollisionComponent>()) {
		obj.get<CollisionComponent>().addChecker([&](SceneObject &object) {
			checkCollisionsFor(object);
		});
	}

	return obj;
}

void Scene::checkCollisionsFor(SceneObject &object) {
	for(SceneObject &object2 : m_objects) {
		if(&object != &object2) {
			CollisionSystem::checkCollision(object, object2);
		}
	}

	if (&object != Scene::player) {
		CollisionSystem::checkCollision(object, *Scene::player);
	}
}

