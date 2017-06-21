/*
 * =====================================================================================
 *
 *       Filename:  KeyboardHandler.hpp
 *
 *    Description:
 *
 *        Created:  11/02/2015 15:49:54
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef KEYBOARDHANDLER_HPP_
#define KEYBOARDHANDLER_HPP_

#include <map>

#include "InputHandler.hpp"
#include "SDLHeaders.hpp"
#include "XMLFile.hpp"

class KeyboardHandler : public InputHandler {
	public:
		KeyboardHandler();

		bool isKeyPressed(GameKey key);

	private:
		void addKey(tinyxml2::XMLElement *keys, GameKey key, const char *name);

		std::map<GameKey, int> m_keys;
};

#endif // KEYBOARDHANDLER_HPP_
