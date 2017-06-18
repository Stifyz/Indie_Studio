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
#include "HudManager.hpp"
#include "Scene.hpp"
#include "TextBox.hpp"

#include "INetwork.hpp"

#include "Room.hpp"

class GameState : public ApplicationState {
	public:
		GameState();

		void update() override;

		void networkLoop(INetwork *network);

	private:
		HudManager m_hud;

		Room &m_room;

		Scene m_scene;
		SceneObject *m_sinbad = nullptr;
		SceneObject *m_camera = nullptr;
		std::unique_ptr<TextBox> m_textBox = nullptr;
};

#endif // GAMESTATE_HPP_
