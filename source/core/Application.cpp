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
#include <cstdlib>
#include <ctime>

#include "Application.hpp"
#include "GameState.hpp"

Application::Application(int, char **) : m_stateStack(ApplicationStateStack::getInstance()) {
	srand(time(NULL));

	m_stateStack.push<GameState>();
}

void Application::handleEvents() {
	// TODO
}

// TODO: Add Window
void Application::run() {
	while (false /* m_window.isOpen() */) {
		handleEvents();

		m_clock.updateGame([&] {
			m_stateStack.top()->update();
		});

		m_clock.drawGame([&] {
			// m_window.clear();

			m_stateStack.top()->draw();

			// m_window.update();
		});
	}
}

