/*
 * =====================================================================================
 *
 *       Filename:  Application.cpp
 *
 *    Description:
 *
 *        Created:  21/04/2017 22:09:55
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "GameState.hpp"

#include "MyTestApp.hpp"

void Application::setup() {
	// MyTestApp app;
	// app.initApp();
	// app.getRoot()->startRendering();
	// app.closeApp();

	OgreBites::ApplicationContext::setup();
	Ogre::Root *root = getRoot();
	m_window = getRenderWindow();

	Ogre::SceneManager *sceneMgr = root->createSceneManager(Ogre::ST_GENERIC);
	sceneMgr->addRenderQueueListener(mOverlaySystem);
	// sceneMgr->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2, 1.0));

	Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	shadergen->addSceneManager(sceneMgr);

	m_trayMgr = new OgreBites::TrayManager("TrayManager", mWindow);
	m_trayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
	m_trayMgr->showLogo(OgreBites::TL_BOTTOMRIGHT);
	m_trayMgr->showCursor();

	m_stateStack.push<GameState>();

	ResourceHandler::setInstance(&m_resourceHandler);
}

void Application::run() {
	while (!m_window->isClosed()) {
		m_clock.updateGame([&] {
			m_stateStack.top()->update();
		});

		m_clock.drawGame([&] {
			getRoot()->renderOneFrame();

			// m_window.clear();

			// m_stateStack.top()->draw();

			// m_window.refresh();
		});
	}
}

bool Application::keyPressed(const OgreBites::KeyboardEvent &evt) {
	if (evt.keysym.sym == SDLK_ESCAPE) {
		getRoot()->queueEndRendering();
	}

	return OgreBites::InputListener::keyPressed(evt);
}

bool Application::keyReleased(const OgreBites::KeyboardEvent& evt) {
	return OgreBites::InputListener::keyReleased(evt);
}

bool Application::mouseMoved(const OgreBites::MouseMotionEvent& evt) {
	return OgreBites::InputListener::mouseMoved(evt);
}

bool Application::mouseWheelRolled(const OgreBites::MouseWheelEvent& evt) {
	return OgreBites::InputListener::mouseWheelRolled(evt);
}

bool Application::mousePressed(const OgreBites::MouseButtonEvent& evt) {
	return OgreBites::InputListener::mousePressed(evt);
}

bool Application::frameRenderingQueued(const Ogre::FrameEvent &evt) {
	m_trayMgr->frameRendered(evt);

	return OgreBites::ApplicationContext::frameRenderingQueued(evt);
}


