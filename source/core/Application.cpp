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

void 		networkLoop(INetwork *network, bool isServer) {
  chat::TextMsg msg(network->id(), "Yooo !", chat::PUBLIC);

  while (1) {
		try {
	    if (network->get(msg)) {
				if (isServer)
					network->send(msg);
	      if ((msg.m_id != network->id() && msg.m_chan != chat::PRIVATE)
	        || (msg.m_chan == chat::PRIVATE && msg.m_idTarget == network->id()))
	        msg.writee();
	    }
		} catch (std::exception &e) {
			if (!isServer) {
				std::cerr << e.what() << '\n';
				break ;
			}
		}
  }
}

Application::Application(int const argc, char **argv) : OgreBites::ApplicationContext("Indie Studio") {
	addInputListener(this);

	if (argc < 2) {
		m_network.reset(new Server(true));
		m_networkThread.reset(new std::thread(networkLoop, m_network.get(), true));
	} else if (argc > 2) {
		m_network.reset(new Client(std::stoi(argv[1]), true, argv[2]));
		m_networkThread.reset(new std::thread(networkLoop, m_network.get(), false));
	} else {
		m_network.reset(new Client(std::stoi(argv[1]), true));
		m_networkThread.reset(new std::thread(networkLoop, m_network.get(), false));
	}

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

	m_trayManager = new OgreBites::TrayManager("TrayManager", mWindow);
	m_trayManager->showFrameStats(OgreBites::TL_BOTTOMLEFT);
	m_trayManager->showLogo(OgreBites::TL_BOTTOMRIGHT);
	m_trayManager->refreshCursor();
	m_trayManager->showCursor();

	Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	shadergen->addSceneManager(sceneManager);

	OgreData::getInstance().init(root, mWindow, sceneManager, this, m_trayManager, m_network.get());

	m_stateStack.push<GameState>();
}

void Application::run() {
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
	m_trayManager->keyPressed(evt);
	return true;
}

bool Application::keyReleased(const OgreBites::KeyboardEvent& evt) {
	m_trayManager->keyReleased(evt);
	return true;
}

bool Application::mouseMoved(const OgreBites::MouseMotionEvent& evt) {
	m_trayManager->mouseMoved(evt);
	return true;
}

bool Application::mouseWheelRolled(const OgreBites::MouseWheelEvent& evt) {
	m_trayManager->mouseWheelRolled(evt);
	return true;
}

bool Application::mousePressed(const OgreBites::MouseButtonEvent& evt) {
	m_trayManager->mousePressed(evt);
	return true;
}

bool Application::mouseReleased(const OgreBites::MouseButtonEvent& evt) {
	m_trayManager->mouseReleased(evt);
	return true;
}

bool Application::frameRenderingQueued(const Ogre::FrameEvent &evt) {
	m_trayManager->frameRendered(evt);
	return true;
}
