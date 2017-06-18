/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* Background.cpp for project :
|*                                                          *|
|* Created: 2017-06-15 13:44
|*                                                          *|
\************************************************************/

#include "Background.hpp"
#include "OgreData.hpp"

// #include <Ogre.h>
// #include <OgreAxisAlignedBox.h>
#include <OgreMaterial.h>
#include <OgreRenderQueueSortingGrouping.h>
#include <OgreSceneNode.h>
#include <OgreTechnique.h>
// #include <OgreMaterialManager.h>

void Background::init(const std::string &fileName, const std::string &sceneName) {
	// Create background material
	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create(fileName + "_" + sceneName, "General");
	material->getTechnique(0)->getPass(0)->createTextureUnitState(fileName);
	material->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
	material->getTechnique(0)->getPass(0)->setDepthWriteEnabled(false);
	material->getTechnique(0)->getPass(0)->setLightingEnabled(false);
}

void Background::set(const std::string &fileName, const std::string &sceneName) {
	// Create background m_rectangle covering the whole screen
	Ogre::Rectangle2D *rect = new Ogre::Rectangle2D(true);
	rect->setCorners(-1.0, 1.0, 1.0, -1.0);
	rect->setMaterial(fileName + "_" + sceneName);

	// Render the background before everything else
	rect->setRenderQueueGroup(0);

	// Use infinite AAB to always stay visible
	Ogre::AxisAlignedBox aabInf;
	aabInf.setInfinite();
	rect->setBoundingBox(aabInf);

	// Attach background to the scene
	Ogre::SceneManager *sceneManager = OgreData::getInstance().sceneManager();
	Ogre::SceneNode* node = sceneManager->getRootSceneNode()->createChildSceneNode("Background");
	node->attachObject(rect);
}

void Background::update() {
}

