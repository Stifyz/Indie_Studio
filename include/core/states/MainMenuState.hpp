/*
 * =====================================================================================
 *
 *       Filename:  MainMenuState.hpp
 *
 *    Description:
 *
 *        Created:  10/06/2017 14:27:42
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAINMENUSTATE_HPP_
#define MAINMENUSTATE_HPP_

#include <OgreTrays.h>
#include <OgreInput.h>

#include "ApplicationState.hpp"

class MainMenuState : public ApplicationState, public OgreBites::TrayListener {
	public:
		MainMenuState(OgreBites::TrayManager *trayManager);

		void update() override;

		void buttonHit(OgreBites::Button *button) override;
};

#endif // MAINMENUSTATE_HPP_
