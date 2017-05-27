/*
 * =====================================================================================
 *
 *       Filename:  ApplicationState.hpp
 *
 *    Description:
 *
 *        Created:  15/09/2014 00:16:41
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef APPLICATIONSTATE_HPP_
#define APPLICATIONSTATE_HPP_

#include <OgreSceneManager.h>

class ApplicationStateStack;

class ApplicationState {
	public:
		ApplicationState(ApplicationState *parent = nullptr) : m_parent(parent) {}
		ApplicationState(const ApplicationState &) = delete;
		ApplicationState(ApplicationState &&) = default;
		virtual ~ApplicationState() = default;

		virtual void init() = 0;

		virtual void update() = 0;

		void setStateStack(ApplicationStateStack *stateStack) { m_stateStack = stateStack; }

		void setSceneManager(Ogre::SceneManager *sceneManager) { m_sceneManager = sceneManager; }

	protected:
		ApplicationState *m_parent = nullptr;

		ApplicationStateStack *m_stateStack = nullptr;

		Ogre::SceneManager *m_sceneManager;
};

#include "ApplicationStateStack.hpp"

#endif // APPLICATIONSTATE_HPP_
