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

#include "GameClock.hpp"

class Application {
	public:
		Application(int argc, char **argv);

		void run();

	private:
		bool m_isRunning = true;

		GameClock m_clock;
};

#endif // APPLICATION_HPP_
