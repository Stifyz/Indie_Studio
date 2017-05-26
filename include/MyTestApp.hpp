/*
 * =====================================================================================
 *
 *       Filename:  MyTestApp.hpp
 *
 *    Description:
 *
 *        Created:  26/05/2017 03:25:46
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MYTESTAPP_HPP_
#define MYTESTAPP_HPP_

#include <memory>

#include <OgreApplicationContext.h>
#include <OgreFrameListener.h>
#include <OgreInput.h>
#include <OgreTrays.h>

#include "MyTestRoom.hpp"
#include "SinbadCharacterController.hpp"

class MyTestApp : public OgreBites::ApplicationContext, public OgreBites::InputListener {
	public:
		MyTestApp();

		bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
		bool keyReleased(const OgreBites::KeyboardEvent& evt) override;
		bool mouseMoved(const OgreBites::MouseMotionEvent& evt) override;
		bool mouseWheelRolled(const OgreBites::MouseWheelEvent& evt) override;
		bool mousePressed(const OgreBites::MouseButtonEvent& evt) override;

		bool frameRenderingQueued(const Ogre::FrameEvent& evt) override;

		void setup() override;

	private:
		OgreBites::TrayManager *m_trayMgr = nullptr;

		MyTestRoom m_room;
		SinbadCharacterController *m_chara = nullptr;
};

#endif // MYTESTAPP_HPP_
