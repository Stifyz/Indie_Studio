/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* GamePadMovement.cpp for project :
|*                                                          *|
|* Created: 2017-05-31 20:15
|*                                                          *|
\************************************************************/

#include "GamePadMovement.hpp"
#include "PositionComponent.hpp"

#include <OgreVector3.h>

void GamePadMovement::process(SceneObject &object) {
	Ogre::Vector3 v(0, 0, 0);
	auto &positionComponent = object.get<PositionComponent>();

	if (GamePad::isKeyPressed(GameKey::Left))
		v.x -= 1;
	else if (GamePad::isKeyPressed(GameKey::Right))
		v.x += 1;
	else if (GamePad::isKeyPressed(GameKey::Up))
		v.y -= 1;
	else if (GamePad::isKeyPressed(GameKey::Down))
		v.y += 1;
	positionComponent.updateDirection(v);
}
