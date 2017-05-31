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

		OgreBites::ApplicationContext *app() { return m_app; }

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
};

#endif // OGREDATA_HPP_