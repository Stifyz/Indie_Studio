/*
 * =====================================================================================
 *
 *       Filename:  EnemyMovement.hpp
 *
 *    Description:
 *
 *        Created:  19/06/2017 15:28:13
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ENEMYMOVEMENT_HPP_
#define ENEMYMOVEMENT_HPP_

#include "Movement.hpp"

class EnemyMovement : public Movement {
	public:
		void process(SceneObject &object) override;
};

#endif // ENEMYMOVEMENT_HPP_
