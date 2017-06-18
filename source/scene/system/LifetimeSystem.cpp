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
#include "AnimationListComponent.hpp"
#include "LifetimeComponent.hpp"
#include "LifetimeSystem.hpp"
#include "OgreData.hpp"
#include "SceneNodeComponent.hpp"

#include "Debug.hpp"

void LifetimeSystem::process(SceneObjectList &objects) {
	for(size_t i = 0 ; i < objects.size() ; i++) {
		if(objects[i].has<LifetimeComponent>()
		&& objects[i].get<LifetimeComponent>().dead(objects[i])) {
			if ((objects[i].type() == "Player" || objects[i].type() == "Enemy") && objects[i].name() != "Sinbad") {
				if (objects[i].has<AnimationListComponent>() && !objects[i].get<AnimationListComponent>().isAnimationFinished("Die")) {
					continue;
				}
			}

			Ogre::SceneNode *node = objects[i].get<SceneNodeComponent>().root;
			OgreData::getInstance().sceneManager()->destroySceneNode(node);

			if (objects[i].type() == "Player")
				OgreData::getInstance().trayManager()->removeWidgetFromTray("PlayerBar_" + objects[i].name());

			objects.remove(i--);
		}
	}
}

