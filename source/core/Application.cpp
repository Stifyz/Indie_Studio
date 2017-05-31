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
#include "OgreData.hpp"

Application::Application() : OgreBites::ApplicationContext("Indie Studio") {
	addInputListener(this);
}

void Application::setup() {
	OgreBites::ApplicationContext::setup();
	Ogre::Root *root = getRoot();

	Ogre::SceneManager *sceneManager = root->createSceneManager(Ogre::ST_GENERIC);
	sceneManager->addRenderQueueListener(mOverlaySystem);
	// sceneManager->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2, 1.0));

	m_trayManager = new OgreBites::TrayManager("TrayManager", mWindow);
	m_trayManager->showFrameStats(OgreBites::TL_BOTTOMLEFT);
	m_trayManager->showLogo(OgreBites::TL_BOTTOMRIGHT);
	m_trayManager->showCursor();

	Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	shadergen->addSceneManager(sceneManager);

	OgreData::getInstance().init(root, mWindow, sceneManager, this);

	m_stateStack.push<GameState>();

	ResourceHandler::setInstance(&m_resourceHandler);
}

void Application::run() {
	// getRoot()->startRendering();
	// return;

	Ogre::Root *root = getRoot();
	root->getRenderSystem()->_initRenderTargets();
	root->clearEventTimes();

	bool isRunning = true;
	while (isRunning && !root->endRenderingQueued()) {
		Ogre::WindowEventUtilities::messagePump();

		m_clock.updateGame([&] {
			m_stateStack.top()->update();
		});

		m_clock.drawGame([&] {
			if (mWindow && mWindow->isActive() && !root->renderOneFrame())
				isRunning = false;
			}
		);
	}
}

bool Application::keyPressed(const OgreBites::KeyboardEvent &evt) {
	if (evt.keysym.sym == SDLK_ESCAPE) {
		getRoot()->queueEndRendering();
	}

	return true;
}

bool Application::keyReleased(const OgreBites::KeyboardEvent& evt) {
	return true;
}

bool Application::mouseMoved(const OgreBites::MouseMotionEvent& evt) {
	return true;
}

bool Application::mouseWheelRolled(const OgreBites::MouseWheelEvent& evt) {
	return true;
}

bool Application::mousePressed(const OgreBites::MouseButtonEvent& evt) {
	return true;
}

bool Application::frameRenderingQueued(const Ogre::FrameEvent &evt) {
	m_trayManager->frameRendered(evt);

	return true;
}


