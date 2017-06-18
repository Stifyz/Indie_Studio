/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* MainMenuState.hpp for project :
|*                                                          *|
|* Created: 2017-06-15 13:25
|*                                                          *|
\************************************************************/

#ifndef MAINMENUSTATE_HPP_
#define MAINMENUSTATE_HPP_

#include <OgreCamera.h>

#include "ApplicationState.hpp"
#include "Background.hpp"
#include "Scene.hpp"

class MainMenuState : public ApplicationState {
	public:
		MainMenuState();

		void update() override;

		void buttonHit(OgreBites::Button *button) override;
	private:
		Background m_background;
		Ogre::Camera *m_camera;
};

#endif // !MAINMENUSTATE_HPP_
