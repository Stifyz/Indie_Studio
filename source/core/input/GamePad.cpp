/*
 * =====================================================================================
 *
 *       Filename:  GamePad.cpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 13:46:38
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "GameClock.hpp"
#include "GamePad.hpp"

InputHandler *GamePad::s_inputHandler = nullptr;

std::map<GameKey, bool> GamePad::s_keysPressed = {
	{GameKey::Left,   false},
	{GameKey::Right,  false},
	{GameKey::Up,     false},
	{GameKey::Down,   false},

	{GameKey::A,      false},
	{GameKey::B,      false},

	{GameKey::Start,  false},
	{GameKey::Select, false}
};

std::map<GameKey, u32> GamePad::s_lastTimePressed = {
	{GameKey::Left,     0},
	{GameKey::Right,    0},
	{GameKey::Up,       0},
	{GameKey::Down,     0},

	{GameKey::A,        0},
	{GameKey::B,        0},

	{GameKey::Start,    0},
	{GameKey::Select,   0}
};

bool GamePad::s_verticalLock = false;
bool GamePad::s_horizontalLock = false;

GameKey GamePad::s_verticalValue = GameKey::Down;
GameKey GamePad::s_horizontalValue = GameKey::Left;

bool GamePad::isKeyPressed(GameKey key) {
	if(!s_inputHandler)
		return false;

	for (unsigned int i = 0 ; i < 4 ; ++i) {
		if (key == static_cast<GameKey>(i)) {
			bool &lock = (i < 2) ? s_horizontalLock : s_verticalLock;
			GameKey &value = (i < 2) ? s_horizontalValue : s_verticalValue;

			if (lock && value == static_cast<GameKey>(i))
				return false;
			else if (s_inputHandler->isKeyPressed(key)) {
				lock = true;
				value = static_cast<GameKey>(i + (i % 2 ? 1 : -1));
				return true;
			}
			else {
				lock = false;
				return false;
			}
		}
	}

	return s_inputHandler->isKeyPressed(key);
}

bool GamePad::isKeyPressedOnce(GameKey key) {
	if(GamePad::isKeyPressed(key)) {
		if(!s_keysPressed[key]) {
			s_keysPressed[key] = true;
			return true;
		} else {
			return false;
		}
	} else {
		s_keysPressed[key] = false;
		return false;
	}
}

bool GamePad::isKeyPressedWithDelay(GameKey key, u16 delay) {
	if(GamePad::isKeyPressed(key) && GameClock::getTicks() - s_lastTimePressed[key] > delay) {
		s_lastTimePressed[key] = GameClock::getTicks();
		return true;
	} else {
		if(!GamePad::isKeyPressed(key)) s_lastTimePressed[key] = 0;
		return false;
	}
}

