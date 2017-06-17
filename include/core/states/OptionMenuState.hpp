/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* OptionMenuState.hpp for project :
|*                                                          *|
|* Created: 2017-06-15 11:31
|*                                                          *|
\************************************************************/

#ifndef OPTIONMENUSTATE_HPP_
#define OPTIONMENUSTATE_HPP_

#include <OgreTrays.h>
#include <OgreInput.h>

#include "ApplicationState.hpp"
#include "Background.hpp"

class OptionMenuState : public ApplicationState, public OgreBites::TrayListener {
	public:
		OptionMenuState();

		void update() override;

		void buttonHit(OgreBites::Button *button) override;
	private :
};

#endif // !OPTIONMENUSTATE_HPP_
