/*
 * =====================================================================================
 *
 *       Filename:  KeyboardHandler.cpp
 *
 *    Description:
 *
 *        Created:  11/02/2015 15:49:47
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Debug.hpp"
#include "IntTypes.hpp"
#include "KeyboardHandler.hpp"

KeyboardHandler::KeyboardHandler() {
	XMLFile doc("res/config/keyboard_keys.xml");
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

bool KeyboardHandler::isKeyPressed(GameKey key) {
	const u8 *keyboardState = SDL_GetKeyboardState(nullptr);
	SDL_Scancode keyScancode = SDL_GetScancodeFromKey(m_keys[key]);

	return keyboardState[keyScancode];
}

// Reading keys from names as defined here: https://wiki.libsdl.org/SDL_Keycode
void KeyboardHandler::addKey(tinyxml2::XMLElement *keys, GameKey key, const char *name) {
	tinyxml2::XMLElement *keyElement = keys->FirstChildElement(name);
	m_keys[key] = SDL_GetKeyFromName(keyElement->Attribute("key"));

	if(m_keys[key] == SDLK_UNKNOWN) {
		DEBUG("Key '", keyElement->Attribute("key"), "' not recognized");
	}
};

