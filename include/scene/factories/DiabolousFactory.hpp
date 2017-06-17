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
#ifndef DIABOLOUSFACTORY_HPP_
#define DIABOLOUSFACTORY_HPP_

#include "SceneObject.hpp"

#define DIABOLOUS_HEIGHT (5 / 1.8)

class DiabolousFactory {
	public:
		static SceneObject create();
};

#endif // DIABOLOUSFACTORY_HPP_
