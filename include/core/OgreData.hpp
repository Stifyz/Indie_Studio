/*
 * =====================================================================================
 *
 *       Filename:  OgreData.hpp
 *
 *    Description:
 *
 *        Created:  27/05/2017 16:01:15
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef OGREDATA_HPP_
#define OGREDATA_HPP_

#include <OgreApplicationContext.h>
#include <OgreRoot.h>
#include <OgreRenderWindow.h>
#include <OgreSceneManager.h>
#include <OgreTrays.h>

class OgreData {
	public:
		void init(Ogre::Root *root, Ogre::RenderWindow *renderWindow, Ogre::SceneManager *sceneManager, OgreBites::ApplicationContext *app) {
			m_root = root;
			m_renderWindow = renderWindow;
			m_sceneManager = sceneManager;

			m_app = app;
		}

		Ogre::Root *root() const { return m_root; }
		Ogre::RenderWindow *renderWindow() const { return m_renderWindow; }
		Ogre::SceneManager *sceneManager() const { return m_sceneManager; }

		OgreBites::ApplicationContext *app() const { return m_app; }
		OgreBites::TrayManager *trayManager() const { return m_trayManager; }

		std::string &chatBuffer() { return m_chatBuffer; }

		void setTrayManager(OgreBites::TrayManager *trayManager) { m_trayManager = trayManager; }

		static OgreData &getInstance() {
			static OgreData data;
			return data;
		}

		bool keyboardIsTextMod = false;

		void setLastPressed(OgreBites::KeyboardEvent evt) {
			m_lastPressed = evt;
			m_isLastPressed = true;
		}
		void setLastReleased(OgreBites::KeyboardEvent evt) {
			m_lastReleased = evt;
			m_isLastReleased = true;
		}
		const OgreBites::KeyboardEvent *getLastPressed() {
			if (!m_isLastPressed)
				return nullptr;
			m_isLastPressed = false;
			return &m_lastPressed;
		}
		const OgreBites::KeyboardEvent *getLastReleased() {
			if (!m_isLastReleased)
				return nullptr;
			m_isLastReleased = false;
			return &m_lastReleased;
		}
	private:
		OgreBites::KeyboardEvent m_lastPressed;
		OgreBites::KeyboardEvent m_lastReleased;

		std::string m_chatBuffer;

		bool m_isLastPressed = false;
		bool m_isLastReleased = false;
		OgreData() = default;


		Ogre::Root *m_root = nullptr;
		Ogre::RenderWindow *m_renderWindow = nullptr;
		Ogre::SceneManager *m_sceneManager = nullptr;

		OgreBites::ApplicationContext *m_app = nullptr;
		OgreBites::TrayManager *m_trayManager = nullptr;
};

#endif // OGREDATA_HPP_
