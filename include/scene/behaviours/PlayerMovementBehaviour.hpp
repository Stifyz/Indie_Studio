/*
 * =====================================================================================
 *
 *       Filename:  PlayerMovementBehaviour.hpp
 *
 *    Description:
 *
 *        Created:  15/06/2017 18:14:02
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYERMOVEMENTBEHAVIOUR_HPP_
#define PLAYERMOVEMENTBEHAVIOUR_HPP_

#include "Behaviour.hpp"

class PlayerMovementBehaviour : public Behaviour {
	using AnimList = std::vector<const char *>;

	public:
		PlayerMovementBehaviour(AnimList &&idleAnimations, AnimList &&walkAnimations);

		void update(SceneObject &object) override;

	private:
		void updateAnimation(SceneObject &object);
		void updateDirection(SceneObject &object);

		bool m_oldMovingState = false;

		AnimList m_idleAnimations;
		AnimList m_walkAnimations;
};

#endif // PLAYERMOVEMENTBEHAVIOUR_HPP_
