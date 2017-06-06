/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* GamePadMovement.cpp for project :
|*                                                          *|
|* Created: 2017-05-31 20:15
|*                                                          *|
\************************************************************/

#include "GameKey.hpp"
#include "GamePadMovement.hpp"
#include "MovementComponent.hpp"
#include "SceneNodeComponent.hpp"

void GamePadMovement::process(SceneObject &object) {
	auto &movementComponent = object.get<MovementComponent>();

	if (GamePad::isKeyPressed(GameKey::Left)) {
		movementComponent.v.x = -1;
	}
	else if (GamePad::isKeyPressed(GameKey::Right)) {
		movementComponent.v.x = 1;
	}

	if (GamePad::isKeyPressed(GameKey::Up)) {
		movementComponent.v.z = -1;
	}
	else if (GamePad::isKeyPressed(GameKey::Down)) {
		movementComponent.v.z = 1;
	}

	if (movementComponent.v.x && movementComponent.v.z) {
		movementComponent.v.x /= 1.41;
		movementComponent.v.z /= 1.41;
	}
}
