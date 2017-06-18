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

#include <memory>

#include <OgreTrays.h>
#include <OgreInput.h>

#include "OgreData.hpp"

class ApplicationStateStack;

class ApplicationState : public OgreBites::TrayListener {
	public:
		ApplicationState(const std::string &name = "", ApplicationState *parent = nullptr) : m_parent(parent) {
			OgreData::getInstance().setTrayManager(new OgreBites::TrayManager("TrayManager_" + name, OgreData::getInstance().renderWindow()));
			m_trayManager.reset(OgreData::getInstance().trayManager());
			// m_trayManager->refreshCursor();
			// m_trayManager->showCursor();
			m_trayManager->showCursor();
			m_trayManager->setListener(this);
		}

		ApplicationState(const ApplicationState &) = delete;
		ApplicationState(ApplicationState &&) = default;
		virtual ~ApplicationState() = default;

		virtual void update() = 0;

		void hide() {
			m_trayManager->hideTrays();
			m_trayManager->hideCursor();
		}

		void show() {
			m_trayManager->showTrays();
			m_trayManager->showCursor();
			// m_trayManager->setListener(this);
			OgreData::getInstance().setTrayManager(m_trayManager.get());
		}

		void setStateStack(ApplicationStateStack *stateStack) { m_stateStack = stateStack; }

	protected:
		ApplicationState *m_parent = nullptr;

		ApplicationStateStack *m_stateStack = nullptr;

		std::unique_ptr<OgreBites::TrayManager> m_trayManager = nullptr;
};

#include "ApplicationStateStack.hpp"

#endif // APPLICATIONSTATE_HPP_
