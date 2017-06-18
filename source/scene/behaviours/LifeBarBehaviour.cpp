/*
 * =====================================================================================
 *
 *       Filename:  LifeBarBehaviour.cpp
 *
 *    Description:
 *
 *        Created:  18/06/2017 21:15:25
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <OgreBillboardSet.h>

#include "HealthComponent.hpp"
#include "LifeBarBehaviour.hpp"
#include "OgreData.hpp"

static unsigned long int lifeBarCount = 0;

LifeBarBehaviour::LifeBarBehaviour(Ogre::SceneNode *root, const Ogre::Vector3 &pos) {
	Ogre::ColourValue color(0, 1, 0, 1);

	Ogre::SceneNode* myNode = root->createChildSceneNode();
	Ogre::SceneManager *sceneManager = OgreData::getInstance().sceneManager();
	Ogre::BillboardSet* lifeBar = sceneManager->createBillboardSet("LifeBar" + std::to_string(lifeBarCount++));

	m_billboard = lifeBar->createBillboard(pos);
	m_billboard->setColour(Ogre::ColourValue(0, 1, 0, 1));
	m_billboard->setDimensions(s_size, 0.5);

	myNode->attachObject(lifeBar);
}

void LifeBarBehaviour::update(SceneObject &object) {
	auto &healthComponent = object.get<HealthComponent>();

	float percent = (healthComponent.life() * 100.0f) / healthComponent.maxLife();
	if (percent < 25)
		m_billboard->setColour(Ogre::ColourValue(1, 0, 0, 1));

	float rest = (percent * s_size) / 100.0f;
	m_billboard->setDimensions(rest, 0.5);
}

