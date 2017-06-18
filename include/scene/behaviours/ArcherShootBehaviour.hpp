/*
 * =====================================================================================
 *
 *       Filename:  ArcherShootBehaviour.hpp
 *
 *    Description:
 *
 *        Created:  16/06/2017 08:44:35
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ARCHERSHOOTBEHAVIOUR_HPP_
#define ARCHERSHOOTBEHAVIOUR_HPP_

#include "AnimationListComponent.hpp"
#include "AttackBehaviour.hpp"

class ArcherShootBehaviour : public AttackBehaviour {
	public:
		ArcherShootBehaviour() : AttackBehaviour("Attack") {}

		void action(SceneObject &object) override;
};

#endif // ARCHERSHOOTBEHAVIOUR_HPP_
