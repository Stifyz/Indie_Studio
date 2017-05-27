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

#include "MyTestRoom.hpp"
#include "SinbadCharacterController.hpp"

class GameState : public ApplicationState {
	public:
		void init() override;

		void update() override;

	private:
		MyTestRoom m_room;
		SinbadCharacterController m_chara;

		Scene m_scene;
};

#endif // GAMESTATE_HPP_
