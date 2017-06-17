/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* PauseMenuState.hpp for project :
|*                                                          *|
|* Created: 2017-06-15 11:13
|*                                                          *|
\************************************************************/

#ifndef PAUSEMENUSTATE_HPP_
#define PAUSEMENUSTATE_HPP_

#include <OgreTrays.h>
#include <OgreInput.h>

#include "ApplicationState.hpp"

class PauseMenuState : public ApplicationState, public OgreBites::TrayListener {
	public:
		PauseMenuState();

		void update() override;

		void buttonHit(OgreBites::Button *button) override;
};

#endif // !PAUSEMENUSTATE_HPP_
