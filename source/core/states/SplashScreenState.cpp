#include "GameState.hpp"
#include "SplashScreenState.hpp"
#include "OptionMenuState.hpp"

#include <Ogre.h>

SplashScreenState::SplashScreenState() : ApplicationState("SplashScreen") {
	m_background.init("gauntlet.png", "SplashScreen");
	m_background.set();

	auto *sceneManager = OgreData::getInstance().sceneManager();
	m_camera = sceneManager->createCamera("Camera_Menu");
	m_camera->setAutoAspectRatio(true);
	m_camera->setNearClipDistance(0.1);

	m_camera->setFarClipDistance(1000);

	Ogre::RenderWindow *renderWindow = OgreData::getInstance().renderWindow();
	renderWindow->addViewport(m_camera);
}

void SplashScreenState::update() {
	m_background.update();
}

 void SplashScreenState::buttonHit(OgreBites::Button *button) {}

