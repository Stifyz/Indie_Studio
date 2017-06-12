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

namespace Mouse {
	enum class Button {
		Left   = 1,
		Middle = 2,
		Right  = 3
	};

	bool isButtonPressed(Button button);

	Ogre::Vector2 getPosition();
};

#endif // MOUSE_HPP_
