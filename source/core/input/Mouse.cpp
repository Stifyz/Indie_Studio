/*
 * =====================================================================================
 *
 *       Filename:  Mouse.cpp
 *
 *    Description:
 *
 *        Created:  12/06/2017 09:36:06
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "IntTypes.hpp"
#include "Mouse.hpp"
#include "SDLHeaders.hpp"

std::map<Mouse::Button, bool> Mouse::s_buttonsPressed = {
	{Mouse::Button::Left,   false},
	{Mouse::Button::Middle, false},
	{Mouse::Button::Right,  false}
};

bool Mouse::isButtonPressed(Button button) {
	return SDL_GetMouseState(NULL, NULL) & static_cast<u32>(button);
}

bool Mouse::isButtonPressedOnce(Button button) {
	if(Mouse::isButtonPressed(button)) {
		if(!s_buttonsPressed[button]) {
			s_buttonsPressed[button] = true;
			return true;
		} else {
			return false;
		}
	} else {
		s_buttonsPressed[button] = false;
		return false;
	}
}

Ogre::Vector2 Mouse::getPosition() {
	int x, y;
	SDL_GetMouseState(&x, &y);

	return Ogre::Vector2{static_cast<float>(x), static_cast<float>(y)};
}

