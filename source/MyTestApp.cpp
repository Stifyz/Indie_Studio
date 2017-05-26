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

	return true;
}

bool MyTestApp::frameRenderingQueued(const Ogre::FrameEvent &evt) {
	m_trayMgr->frameRendered(evt);

	return true;
}

void MyTestApp::setup() {
	// do not forget to call the base first
	OgreBites::ApplicationContext::setup();

	// get a pointer to the already created root
	Ogre::Root *root = getRoot();
	Ogre::SceneManager *scnMgr = root->createSceneManager(Ogre::ST_GENERIC);

	m_trayMgr = new OgreBites::TrayManager("TrayManager", mWindow);
	m_trayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
	m_trayMgr->showLogo(OgreBites::TL_BOTTOMRIGHT);
	// m_trayMgr->toggleAdvancedFrameStats();
	m_trayMgr->hideCursor();

	scnMgr->addRenderQueueListener(mOverlaySystem);

	// register our scene with the RTSS
	Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	shadergen->addSceneManager(scnMgr);

	// without light we would just get a black screen
	Ogre::Light* light = scnMgr->createLight("MainLight");
	light->setPosition(0, 10, 15);

	// also need to tell where we are
	Ogre::SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	camNode->setPosition(0, 0, 15);
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

	// create the camera
	Ogre::Camera* cam = scnMgr->createCamera("myCam");
	cam->setNearClipDistance(5); // specific to this sample
	cam->setAutoAspectRatio(true);
	camNode->attachObject(cam);

	// and tell it to render into the main window
	getRenderWindow()->addViewport(cam);

	// finally something to render
	Ogre::Entity* ent = scnMgr->createEntity("Sinbad.mesh");
	Ogre::SceneNode* node = scnMgr->getRootSceneNode()->createChildSceneNode();
	node->attachObject(ent);
}

