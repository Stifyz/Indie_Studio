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

	m_trayManager->reset(new OgreBites::TrayManager("TrayManager", mWindow));
	m_menu.reset(new MenuState(m_trayManager));
	m_menu->loadMenu(MenuState::MenuType::Main);


	Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	shadergen->addSceneManager(sceneManager);

	OgreData::getInstance().init(root, mWindow, sceneManager, this);

	m_stateStack.push<GameState>();
}

void Application::run() {
	// getRoot()->startRendering();
	// return;

	Ogre::Root *root = getRoot();
	root->getRenderSystem()->_initRenderTargets();
	root->clearEventTimes();

	while (!root->endRenderingQueued()) {
		Ogre::WindowEventUtilities::messagePump();

		m_clock.updateGame([&] {
			m_stateStack.top()->update();
		});

		m_clock.drawGame([&] {
			if (mWindow && mWindow->isActive() && !root->renderOneFrame())
				getRoot()->queueEndRendering();
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


