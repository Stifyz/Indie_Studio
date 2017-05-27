/*
 * =====================================================================================
 *
 *       Filename:  Application.hpp
 *
 *    Description:
 *
 *        Created:  21/04/2017 22:09:41
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

// #include "ApplicationStateStack.hpp"
// #include "GameClock.hpp"
// #include "ResourceHandler.hpp"

class Application {
	public:
		Application(int argc, char **argv);

		// void handleEvents();

		void run();

	private:
		// ApplicationStateStack m_stateStack;
        //
		// GameClock m_clock;

		// ResourceHandler m_resourceHandler;
};

#endif // APPLICATION_HPP_
