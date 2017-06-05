/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* Movement.cpp for project :
|*                                                          *|
|* Created: 2017-06-05 22:02
|*                                                          *|
\************************************************************/

#include "Movement.hpp"

void Movement::turnToUp(Ogre::Quaternion &orientation) {
	orientation.w = 0;
	orientation.x = 0;
	orientation.y = 1;
	orientation.z = 0;
}

void Movement::turnToDown(Ogre::Quaternion &orientation) {
	orientation.w = 1;
	orientation.x = 0;
	orientation.y = 0;
	orientation.z = 0;
}

void Movement::turnToLeft(Ogre::Quaternion &orientation) {
	orientation.w = 0.5;
	orientation.x = 0;
	orientation.y = -0.5;
	orientation.z = 0;
}

void Movement::turnToRight(Ogre::Quaternion &orientation) {
	orientation.w = 0.5;
	orientation.x = 0;
	orientation.y = 0.5;
	orientation.z = 0;
}

void Movement::goUp(Ogre::Vector3 &position, float distance) {
	position.z -= distance;
}

void Movement::goDown(Ogre::Vector3 &position, float distance) {
	position.z += distance;
}

void Movement::goLeft(Ogre::Vector3 &position, float distance) {
	position.x -= distance;
}

void Movement::goRight(Ogre::Vector3 &position, float distance) {
	position.x += distance;
}

