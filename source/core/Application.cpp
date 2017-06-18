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
#include "GamePad.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "OgreData.hpp"

#include "RoomLoader.hpp"

Application::Application() : OgreBites::ApplicationContext("Indie Studio") {
	addInputListener(this);

	GamePad::init(m_keyboardHandler);

	ResourceHandler::setInstance(&m_resourceHandler);
	ResourceHandler::loadConfigFile<RoomLoader>("res/config/rooms.xml");
}

void Application::setup() {
	OgreBites::ApplicationContext::setup();
	Ogre::Root *root = getRoot();

	Ogre::SceneManager *sceneManager = root->createSceneManager(Ogre::ST_GENERIC);
	sceneManager->addRenderQueueListener(mOverlaySystem);
	// sceneManager->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2, 1.0));

	Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	shadergen->addSceneManager(sceneManager);

	OgreData::getInstance().init(root, mWindow, sceneManager, this);

	m_stateStack.push<MainMenuState>();
}

void Application::run() {
	Ogre::Root *root = getRoot();
	root->getRenderSystem()->_initRenderTargets();
	root->clearEventTimes();

	while (!m_stateStack.empty() && !root->endRenderingQueued()) {
		DEBUG("begin loop");
		Ogre::WindowEventUtilities::messagePump();

		m_clock.updateGame([&] {
			m_stateStack.top()->update();
		});

		m_clock.drawGame([&] {
			if (!m_stateStack.empty() && mWindow && mWindow->isActive() && !root->renderOneFrame())
				getRoot()->queueEndRendering();
			}
		);
		m_stateStack.clear();
	}

	OgreData::getInstance().setTrayManager(nullptr);
}

bool Application::keyPressed(const OgreBites::KeyboardEvent &evt) {
	OgreBites::TrayManager *trayManager = OgreData::getInstance().trayManager();

	if (trayManager)
		trayManager->keyPressed(evt);
	return true;
}

bool Application::keyReleased(const OgreBites::KeyboardEvent& evt) {
	OgreBites::TrayManager *trayManager = OgreData::getInstance().trayManager();

	if (trayManager)
		trayManager->keyReleased(evt);
	return true;
}

bool Application::mouseMoved(const OgreBites::MouseMotionEvent& evt) {
	OgreBites::TrayManager *trayManager = OgreData::getInstance().trayManager();

	if (trayManager)
		trayManager->mouseMoved(evt);
	return true;
}

bool Application::mouseWheelRolled(const OgreBites::MouseWheelEvent& evt) {
	OgreBites::TrayManager *trayManager = OgreData::getInstance().trayManager();

	if (trayManager)
		trayManager->mouseWheelRolled(evt);
	return true;
}

bool Application::mousePressed(const OgreBites::MouseButtonEvent& evt) {
	OgreBites::TrayManager *trayManager = OgreData::getInstance().trayManager();

	if (trayManager)
		trayManager->mousePressed(evt);
	return true;
}

bool Application::mouseReleased(const OgreBites::MouseButtonEvent& evt) {
	OgreBites::TrayManager *trayManager = OgreData::getInstance().trayManager();

	if (trayManager)
		trayManager->mouseReleased(evt);
	return true;
}

bool Application::frameRenderingQueued(const Ogre::FrameEvent &evt) {
	OgreBites::TrayManager *trayManager = OgreData::getInstance().trayManager();

	if (trayManager)
		trayManager->frameRendered(evt);
	return true;
}


