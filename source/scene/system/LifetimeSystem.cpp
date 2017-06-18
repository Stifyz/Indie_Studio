/*
 * =====================================================================================
 *
 *       Filename:  LifetimeSystem.cpp
 *
 *    Description:
 *
 *        Created:  18/06/2017 16:54:25
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "LifetimeComponent.hpp"
#include "LifetimeSystem.hpp"
#include "OgreData.hpp"
#include "SceneNodeComponent.hpp"

void LifetimeSystem::process(SceneObjectList &objects) {
	for(u16 i = 0 ; i < objects.size() ; i++) {
		if(objects[i].has<LifetimeComponent>()
		&& objects[i].get<LifetimeComponent>().dead(objects[i])) {
			Ogre::SceneNode *node = objects[i].get<SceneNodeComponent>().root;
			OgreData::getInstance().sceneManager()->destroySceneNode(node);

			objects.remove(i--);
		}
	}
}

