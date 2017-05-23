/*
 * =====================================================================================
 *
 *       Filename:  SpriteComponent.hpp
 *
 *    Description:
 *
 *        Created:  22/04/2017 03:49:49
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SPRITECOMPONENT_HPP_
#define SPRITECOMPONENT_HPP_

class SpriteComponent {
	public:
		SpriteComponent(const unsigned int _spritesheet, const unsigned int _index)
			: spritesheet(_spritesheet), index(_index) {}

		const unsigned int spritesheet;
		const unsigned int index;
};

#endif // SPRITECOMPONENT_HPP_
