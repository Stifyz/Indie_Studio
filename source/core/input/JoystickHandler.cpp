/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* JoystickHandler.cpp for project :
|*                                                          *|
|* Created: 2017-06-17 22:23
|*                                                          *|
\************************************************************/

#include "JoystickHandler.hpp"
#include "Debug.hpp"
#include "IntTypes.hpp"

JoystickHandler::JoystickHandler() {
	XMLFile doc("res/config/joystick_keys.xml");
	tinyxml2::XMLElement *keys = doc.FirstChildElement("keys").ToElement();

	addKey(keys, GameKey::Left,  "Left");
	addKey(keys, GameKey::Right, "Right");
	addKey(keys, GameKey::Up,    "Up");
	addKey(keys, GameKey::Down,  "Down");

	addKey(keys, GameKey::A, "A");
	addKey(keys, GameKey::B, "B");

	addKey(keys, GameKey::Start,  "Start");
	addKey(keys, GameKey::Select, "Select");
}

bool JoystickHandler::isKeyPressed(GameKey key) {
	const u8 *keyboardState = SDL_GetKeyboardState(nullptr);
	SDL_Scancode keyScancode = SDL_GetScancodeFromKey(m_keys[key]);

	return keyboardState[keyScancode];
}

// Reading keys from names as defined here: https://wiki.libsdl.org/SDL_Keycode
void JoystickHandler::addKey(tinyxml2::XMLElement *keys, GameKey key, const char *name) {
	tinyxml2::XMLElement *keyElement = keys->FirstChildElement(name);
	m_keys[key] = SDL_GetKeyFromName(keyElement->Attribute("key"));

	if(m_keys[key] == SDLK_UNKNOWN) {
		DEBUG("Key '", keyElement->Attribute("key"), "' not recognized");
	}
};

