/*
 * =====================================================================================
 *
 *       Filename:  GameState.hpp
 *
 *    Description:
 *
 *        Created:  25/05/2017 00:28:13
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include "ApplicationState.hpp"
#include "Scene.hpp"

class GameState : public ApplicationState {
	public:
		void update() override;

		void draw() override;

	private:
		Scene m_scene;
};

#endif // GAMESTATE_HPP_
