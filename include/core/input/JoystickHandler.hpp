/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* JoystickHandler.hpp for project :
|*                                                          *|
|* Created: 2017-06-17 22:19
|*                                                          *|
\************************************************************/

#ifndef JOYSTICKHANDLER_HPP_
#define JOYSTICKHANDLER_HPP_

#include <map>

#include "InputHandler.hpp"
#include "SDLHeaders.hpp"
#include "XMLFile.hpp"

class JoystickHandler {
	public:
		JoystickHandler();

		bool isKeyPressed(GameKey key);
	private:
		void addKey(tinyxml2::XMLElement *keys, GameKey key, const char *name);

		std::map<GameKey, SDL_Keycode> m_keys;
};

#endif // !JOYSTICKHANDLER_HPP_
