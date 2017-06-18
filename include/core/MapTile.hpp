/*
 * =====================================================================================
 *
 *       Filename:  MapTile.hpp
 *
 *    Description:
 *
 *        Created:  21/06/2017 02:18:02
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAPTILE_HPP_
#define MAPTILE_HPP_

#include "IntTypes.hpp"

enum class MapTile : u16 {
	Floor,
	Wall,
	Gold,
	Torch,
	Heart,
	CelticCross,
	Spawner
};

#endif // MAPTILE_HPP_
