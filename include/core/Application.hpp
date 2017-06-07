/*
 * =====================================================================================
 *
 *       Filename:  Application.hpp
 *
 *    Description:
 *
 *        Created:  21/04/2017 22:09:41
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include <OgreApplicationContext.h>
#include <OgreInput.h>
#include <OgreTrays.h>

#include "ApplicationStateStack.hpp"
#include "GameClock.hpp"
#include "KeyboardHandler.hpp"
#include "Ui.hpp"
#include "ResourceHandler.hpp"

class Application : public OgreBites::ApplicationContext, public OgreBites::InputListener {
	public:
		Application();

		void setup() override;

		void run();

		bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
		bool keyReleased(const OgreBites::KeyboardEvent& evt) override;
		bool mouseMoved(const OgreBites::MouseMotionEvent& evt) override;
		bool mouseWheelRolled(const OgreBites::MouseWheelEvent& evt) override;
		bool mousePressed(const OgreBites::MouseButtonEvent& evt) override;

		bool frameRenderingQueued(const Ogre::FrameEvent& evt) override;

	private:
		ApplicationStateStack m_stateStack;
		GameClock m_clock;
		KeyboardHandler m_keyboardHandler;
		ResourceHandler m_resourceHandler;

		std::unique_ptr<OgreBites::TrayManager> m_trayManager = nullptr;
		Ui m_ui;
};

#endif // APPLICATION_HPP_
