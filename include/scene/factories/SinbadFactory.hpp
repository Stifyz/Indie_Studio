/*
 * =====================================================================================
 *
 *       Filename:  SinbadFactory.hpp
 *
 *    Description:
 *
 *        Created:  28/05/2017 13:21:23
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SINBADFACTORY_HPP_
#define SINBADFACTORY_HPP_

#include "CollisionComponent.hpp"

#define CHAR_HEIGHT (5 / 1.8)

class SinbadFactory {
	public:
		static SceneObject create();

	private:
		static void swordAction(SceneObject &sinbad, SceneObject &object, const CollisionInfo &infos);
};

#endif // SINBADFACTORY_HPP_
