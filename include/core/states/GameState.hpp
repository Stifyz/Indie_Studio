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

#include <OgreFrameListener.h>
#include <OgreInput.h>

#include "ApplicationState.hpp"
#include "Scene.hpp"

#include "MyTestRoom.hpp"
#include "SinbadCharacterController.hpp"

class GameState : public ApplicationState, public Ogre::FrameListener, public OgreBites::InputListener {
	public:
		GameState();

		void update() override;

		bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
		bool keyReleased(const OgreBites::KeyboardEvent& evt) override;
		bool mouseMoved(const OgreBites::MouseMotionEvent& evt) override;
		bool mouseWheelRolled(const OgreBites::MouseWheelEvent& evt) override;
		bool mousePressed(const OgreBites::MouseButtonEvent& evt) override;

		bool frameRenderingQueued(const Ogre::FrameEvent& evt) override;

	private:
		MyTestRoom m_room;
		SinbadCharacterController m_chara;

		Scene m_scene;
};

#endif // GAMESTATE_HPP_
