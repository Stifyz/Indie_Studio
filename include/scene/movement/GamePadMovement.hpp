/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* GamePadMovement.hpp for project :
|*                                                          *|
|* Created: 2017-05-31 20:14
|*                                                          *|
\************************************************************/

#ifndef GAMEPADMOVEMENT_HPP_
#define GAMEPADMOVEMENT_HPP_

#include "GamePad.hpp"
#include "Movement.hpp"

class GamePadMovement : public Movement {
	public:
		void process(SceneObject &object);
};

#endif // !GAMEPADMOVEMENT_HPP_
