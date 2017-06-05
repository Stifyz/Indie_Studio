/*
 * =====================================================================================
 *
 *       Filename:  ArcherFactory.hpp
 *
 *    Description:
 *
 *        Created:  05/06/2017 22:15:18
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ARCHERFACTORY_HPP_
#define ARCHERFACTORY_HPP_

#include "SceneObject.hpp"

#define ARCHER_HEIGHT (5 / 1.8)

class ArcherFactory {
	public:
		static SceneObject create();
};

#endif // ARCHERFACTORY_HPP_
