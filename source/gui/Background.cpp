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

#include <OgreMaterial.h>
#include <OgreRenderQueueSortingGrouping.h>
#include <OgreSceneNode.h>
#include <OgreTechnique.h>

void Background::init(const std::string &filename, const std::string &objectName) {
	m_filename = filename;
	m_objectName = objectName;

	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create(filename + "_" + objectName, "General");
	material->getTechnique(0)->getPass(0)->createTextureUnitState(filename);
	material->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
	material->getTechnique(0)->getPass(0)->setDepthWriteEnabled(false);
	material->getTechnique(0)->getPass(0)->setLightingEnabled(false);
}

void Background::set() {
	Ogre::Rectangle2D *rect = new Ogre::Rectangle2D(true);
	rect->setCorners(-1.0, 1.0, 1.0, -1.0);
	rect->setMaterial(m_filename + "_" + m_objectName);
	rect->setRenderQueueGroup(0);

	Ogre::AxisAlignedBox aabInf;
	aabInf.setInfinite();
	rect->setBoundingBox(aabInf);

	Ogre::SceneManager *sceneManager = OgreData::getInstance().sceneManager();
	Ogre::SceneNode* node = sceneManager->getRootSceneNode()->createChildSceneNode("Background" + m_objectName);
	node->attachObject(rect);
	m_rect = rect;
}

void Background::update() {
}

