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

#include "INetwork.hpp"

class OgreData {
	public:
		void init(Ogre::Root *root, Ogre::RenderWindow *renderWindow, Ogre::SceneManager *sceneManager, OgreBites::ApplicationContext *app, OgreBites::TrayManager *trayManager, INetwork *network) {
			m_root = root;
			m_renderWindow = renderWindow;
			m_sceneManager = sceneManager;

			m_app = app;
			m_trayManager = trayManager;

			m_network = network;
		}

		Ogre::Root *root() const { return m_root; }
		Ogre::RenderWindow *renderWindow() const { return m_renderWindow; }
		Ogre::SceneManager *sceneManager() const { return m_sceneManager; }

		OgreBites::ApplicationContext *app() const { return m_app; }
		OgreBites::TrayManager *trayManager() const { return m_trayManager; }

		INetwork *network() const { return m_network; }

		static OgreData &getInstance() {
			static OgreData data;
			return data;
		}

	private:
		OgreData() = default;

		Ogre::Root *m_root = nullptr;
		Ogre::RenderWindow *m_renderWindow = nullptr;
		Ogre::SceneManager *m_sceneManager = nullptr;

		OgreBites::ApplicationContext *m_app = nullptr;
		OgreBites::TrayManager *m_trayManager = nullptr;

		INetwork *m_network = nullptr;
};

#endif // OGREDATA_HPP_
