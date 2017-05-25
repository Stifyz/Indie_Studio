/*
 * =====================================================================================
 *
 *       Filename:  GameState.cpp
 *
 *    Description:
 *
 *        Created:  25/05/2017 00:29:12
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "GameState.hpp"

void GameState::init() {
	m_sceneManager = m_irrlichtDevice->getSceneManager();

	m_irrlichtDevice->getCursorControl()->setVisible(false);

	irr::scene::IMeshSceneNode *cube = m_sceneManager->addCubeSceneNode(10.0f, 0, -1, irr::core::vector3df(0.0f, 0.0f, 20.0f));
	cube->setMaterialFlag(irr::video::EMF_WIREFRAME, true);
	// cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);

	irr::SKeyMap keyMap[5];
	keyMap[0].Action = irr::EKA_MOVE_FORWARD;
	keyMap[0].KeyCode = irr::KEY_KEY_Z;
	keyMap[1].Action = irr::EKA_MOVE_BACKWARD;
	keyMap[1].KeyCode = irr::KEY_KEY_S;
	keyMap[2].Action = irr::EKA_STRAFE_LEFT;
	keyMap[2].KeyCode = irr::KEY_KEY_Q;
	keyMap[3].Action = irr::EKA_STRAFE_RIGHT;
	keyMap[3].KeyCode = irr::KEY_KEY_D;
	keyMap[4].Action = irr::EKA_JUMP_UP;
	keyMap[4].KeyCode = irr::KEY_SPACE;

	m_sceneManager->addCameraSceneNodeFPS(0, 100.0f, 0.1f, -1, keyMap, 5);
}

void GameState::update() {
	m_scene.update();
}

void GameState::draw() {
	m_sceneManager->drawAll();

	m_scene.draw();
}

