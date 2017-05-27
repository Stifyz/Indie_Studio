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
#include "Application.hpp"
#include "GameState.hpp"

#include "MyTestApp.hpp"

Application::Application(int, char **) {
	// m_clock.setIrrlichtDevice(m_window.device());
    //
	// m_stateStack.setIrrlichtDevice(m_window.device());
	// m_stateStack.push<GameState>();
    //
	// ResourceHandler::setInstance(&m_resourceHandler);

	MyTestApp app;
	app.initApp();
	app.getRoot()->startRendering();
	app.closeApp();
}

// void Application::handleEvents() {
	// TODO
// }

void Application::run() {
	// while (m_window.isOpen()) {
	// 	if (m_window.device()->isWindowActive()) {
	// 		handleEvents();
    //
	// 		m_clock.updateGame([&] {
	// 			m_stateStack.top()->update();
	// 		});
    //
	// 		m_clock.drawGame([&] {
	// 			m_window.clear();
    //
	// 			m_stateStack.top()->draw();
    //
	// 			m_window.refresh();
	// 		});
	// 	}
	// 	else {
	// 		m_window.device()->yield();
	// 	}
	// }
}

