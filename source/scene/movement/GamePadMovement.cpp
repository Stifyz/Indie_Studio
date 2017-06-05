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
#include "PositionComponent.hpp"
#include "SceneNodeComponent.hpp"

void GamePadMovement::process(SceneObject &object) {
	Ogre::SceneNode *node = nullptr;

	if (object.has<SceneNodeComponent>())
		node = object.get<SceneNodeComponent>().node;
	else
		return ;

	Ogre::Quaternion orientation = node->getOrientation();
	Ogre::Vector3 position = node->getPosition();

	if (GamePad::isKeyPressedOnce(GameKey::Left))
	{
		turnToLeft(orientation);
		goLeft(position);
	}
	if (GamePad::isKeyPressedOnce(GameKey::Right))
	{
		turnToRight(orientation);
		goRight(position);
	}
	if (GamePad::isKeyPressedOnce(GameKey::Up))
	{
		turnToUp(orientation);
		goUp(position);
	}
	if (GamePad::isKeyPressedOnce(GameKey::Down))
	{
		turnToDown(orientation);
		goDown(position);
	}
	if (GamePad::isKeyPressedOnce(GameKey::Start))
	{
		std::cout << "Orientation : " << orientation.w << ';' << orientation.x << ';' << orientation.y << ';' << orientation.z << ';' << std::endl;
		std::cout << "Position : " << position.x << ';' << position.y << ';' << position.z << ';' << std::endl;
	}
	node->setOrientation(orientation);
	node->setPosition(position);
}
