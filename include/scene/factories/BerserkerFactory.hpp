/*
 * =====================================================================================
 *
 *       Filename:  BerserkerFactory.hpp
 *
 *    Description:
 *
 *        Created:  05/06/2017 22:15:18
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BERSERKERFACTORY_HPP_
#define BERSERKERFACTORY_HPP_

#include "SceneObject.hpp"

#define BERSERKER_HEIGHT (5 / 1.8)

class BerserkerFactory {
	public:
		static SceneObject create();
};

#endif // BERSERKERFACTORY_HPP_
