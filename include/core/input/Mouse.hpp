/*
 * =====================================================================================
 *
 *       Filename:  Mouse.hpp
 *
 *    Description:
 *
 *        Created:  12/06/2017 09:33:39
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MOUSE_HPP_
#define MOUSE_HPP_

#include <OgreVector2.h>

class Mouse {
	public:
		enum class Button {
			Left   = 1,
			Middle = 2,
			Right  = 3
		};

		static bool isButtonPressed(const Button button);
		static bool isButtonPressedOnce(const Button button);

		static Ogre::Vector2 getPosition();

	private:
		static std::map<Button, bool> s_buttonsPressed;
};

#endif // MOUSE_HPP_
