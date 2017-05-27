/*
 * =====================================================================================
 *
 *       Filename:  MyTestApp.cpp
 *
 *    Description:
 *
 *        Created:  26/05/2017 03:27:17
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */

#include <Ogre.h>
#include <OgreApplicationContext.h>

#include "MyTestApp.hpp"

MyTestApp::MyTestApp() : OgreBites::ApplicationContext("MyTestApp") {
	addInputListener(this);
}

bool MyTestApp::keyPressed(const OgreBites::KeyboardEvent &evt) {
	if (evt.keysym.sym == SDLK_ESCAPE) {
		getRoot()->queueEndRendering();
	}

	m_chara->injectKeyDown(evt);
	return true;
}

bool MyTestApp::keyReleased(const OgreBites::KeyboardEvent& evt) {
	m_chara->injectKeyUp(evt);
	return true;
}

bool MyTestApp::mouseMoved(const OgreBites::MouseMotionEvent& evt) {
	m_chara->injectMouseMove(evt);
	return true;
}

bool MyTestApp::mouseWheelRolled(const OgreBites::MouseWheelEvent& evt) {
	m_chara->injectMouseWheel(evt);
	return true;
}

bool MyTestApp::mousePressed(const OgreBites::MouseButtonEvent& evt) {
	m_chara->injectMouseDown(evt);
	return true;
}

bool MyTestApp::frameRenderingQueued(const Ogre::FrameEvent &evt) {
	m_chara->addTime(evt.timeSinceLastFrame);
	m_trayMgr->frameRendered(evt);

	return true;
}

void MyTestApp::setup() {
	// do not forget to call the base first
	OgreBites::ApplicationContext::setup();

	// get a pointer to the already created root
	Ogre::Root *root = getRoot();
	Ogre::SceneManager *sceneMgr = root->createSceneManager(Ogre::ST_GENERIC);
	// sceneMgr->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2, 1.0));

	m_trayMgr = new OgreBites::TrayManager("TrayManager", mWindow);
	m_trayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
	m_trayMgr->showLogo(OgreBites::TL_BOTTOMRIGHT);
	m_trayMgr->showCursor();

	sceneMgr->addRenderQueueListener(mOverlaySystem);

	// register our scene with the RTSS
	Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	shadergen->addSceneManager(sceneMgr);

	// without light we would just get a black screen
	// Ogre::Light* light = sceneMgr->createLight("MainLight");
	// light->setType(Light::LT_POINT);
	// light->setPosition(-10, 40, 20);
	// light->setSpecularColour(ColourValue::White);

	// also need to tell where we are
	Ogre::SceneNode* camNode = sceneMgr->getRootSceneNode()->createChildSceneNode();
	camNode->setPosition(0, 0, 15);
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

	// create the camera
	Ogre::Camera* cam = sceneMgr->createCamera("myCam");
	cam->setAutoAspectRatio(true);
	camNode->attachObject(cam);

	// and tell it to render into the main window
	getRenderWindow()->addViewport(cam);

	// finally something to render
	m_room.init(sceneMgr);

	m_chara = new SinbadCharacterController(cam);
}

