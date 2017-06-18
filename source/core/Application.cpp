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
#include <cstdlib>
#include <ctime>

#include "Application.hpp"
#include "AudioLoader.hpp"
#include "GamePad.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "OgreData.hpp"

#include "MapLoader.hpp"

#include "NewCharacterCom.hpp"
#include "VectorCom.hpp"

// static bool loop = true;

void 		networkLoop(INetwork *network, bool isServer) {
  chat::TextMsg msg(network->id(), "Yooo !", chat::PUBLIC);
  NewCharacterCom charac;
  com::Packet packet;

  while (network->loop()) {
		try {
      packet.init();
	    if (network->get(packet)) {
				if (isServer)
					network->send(packet);
        if (packet.getType() == com::CHAT && packet.getId() != network->id()) {
          msg.deserialize(packet.getData());
  	      if ((msg.m_id != network->id() && msg.m_chan != chat::PRIVATE)
  	        || (msg.m_chan == chat::PRIVATE && static_cast<unsigned int>(msg.m_idTarget) == network->id()))
            OgreData::getInstance().chatBuffer() += '\n' + msg.getMsg();
        } else if (packet.getType() == com::NEW_PERSO && packet.getId() != network->id()) {
          charac.deserialize(packet.getData());
          // ICI
        }
	    }
		} catch (std::exception &e) {
			if (!isServer) {
				std::cerr << e.what() << '\n';
				network->loop(false);
			}
		}
  }
}

Application::Application(int const argc, char **argv) : OgreBites::ApplicationContext("Indie Studio") {
	srand(time(nullptr));

	addInputListener(this);

	if (argc < 2) {
		m_network.reset(new Server(false));
		m_networkThread.reset(new std::thread(networkLoop, m_network.get(), true));
	} else if (argc > 2) {
		m_network.reset(new Client(std::stoi(argv[1]), false, argv[2]));
		m_networkThread.reset(new std::thread(networkLoop, m_network.get(), false));
	} else {
		m_network.reset(new Client(std::stoi(argv[1]), false));
		m_networkThread.reset(new std::thread(networkLoop, m_network.get(), false));
	}

	GamePad::init(m_keyboardHandler);
}

Application::~Application() {
  if (m_networkThread.get() != nullptr) {
    m_network.get()->loop(false);
    m_networkThread.get()->join();
  }
}

void Application::setup() {
	OgreBites::ApplicationContext::setup();
	Ogre::Root *root = getRoot();

	ResourceHandler::setInstance(&m_resourceHandler);
	ResourceHandler::loadConfigFile<AudioLoader>("res/config/audio.xml");
	ResourceHandler::loadConfigFile<MapLoader>("res/config/maps.xml");

	Ogre::SceneManager *sceneManager = root->createSceneManager(Ogre::ST_GENERIC);
	sceneManager->addRenderQueueListener(mOverlaySystem);
	// sceneManager->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2, 1.0));

	Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	shadergen->addSceneManager(sceneManager);

	OgreData::getInstance().init(root, mWindow, sceneManager, this, m_trayManager, m_network.get());

	// m_stateStack.push<GameState>();
	m_stateStack.push<MainMenuState>();
}

void Application::run() {
	Ogre::Root *root = getRoot();
	root->getRenderSystem()->_initRenderTargets();
	root->clearEventTimes();

	while (!m_stateStack.empty() && !root->endRenderingQueued()) {
		Ogre::WindowEventUtilities::messagePump();

		if (mWindow->isClosed())
			break ;

		m_clock.updateGame([&] {
			m_stateStack.top()->update();
		});

		if (mWindow->isClosed())
			break ;

		m_clock.drawGame([&] {
			if (!m_stateStack.empty() && mWindow && mWindow->isActive() && !root->renderOneFrame())
				getRoot()->queueEndRendering();
			}
		);
		m_stateStack.clear();
	}

	while (!m_stateStack.empty())
		m_stateStack.pop();
	m_stateStack.clear();
	OgreData::getInstance().setTrayManager(nullptr);
}

bool Application::keyPressed(const OgreBites::KeyboardEvent &evt) {
	OgreBites::TrayManager *trayManager = OgreData::getInstance().trayManager();

	if (trayManager) {
		if (!OgreData::getInstance().keyboardIsTextMod)
			trayManager->keyPressed(evt);
		OgreData::getInstance().setLastPressed(evt);
	}
	return true;
}

bool Application::keyReleased(const OgreBites::KeyboardEvent& evt) {
	OgreBites::TrayManager *trayManager = OgreData::getInstance().trayManager();

	if (trayManager) {
		if (!OgreData::getInstance().keyboardIsTextMod)
			trayManager->keyReleased(evt);
		OgreData::getInstance().setLastReleased(evt);
}
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
