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

#include "Room.hpp"

class GameState : public ApplicationState {
	public:
		GameState();

		void update() override;

	private:
		Room &m_room;

		Scene m_scene;
		SceneObject *m_sinbad = nullptr;
		SceneObject *m_camera = nullptr;
};

#endif // GAMESTATE_HPP_
