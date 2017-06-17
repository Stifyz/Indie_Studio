/*
 * =====================================================================================
 *
 *       Filename:  GamePad.hpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 13:46:23
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GAMEPAD_HPP_
#define GAMEPAD_HPP_

#include <map>
#include <memory>

#include "InputHandler.hpp"
#include "IntTypes.hpp"

class GamePad {
	public:
		static void init(InputHandler &inputHandler) { s_inputHandler = &inputHandler; }

		static bool isKeyPressed(const GameKey key);
		static bool isKeyPressedOnce(const GameKey key);
		static bool isKeyPressedWithDelay(const GameKey key, const u16 delay);

	private:
		static InputHandler *s_inputHandler;

		static std::map<GameKey, bool> s_keysPressed;
		static std::map<GameKey, u32> s_lastTimePressed;

		// Lock to avoid bugs when opposite keys are pressed
		static bool s_verticalLock, s_horizontalLock;
		static GameKey s_verticalValue, s_horizontalValue;
};

#endif // GAMEPAD_HPP_
