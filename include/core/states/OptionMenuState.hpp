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

#include "ApplicationState.hpp"
#include "Background.hpp"

class OptionMenuState : public ApplicationState {
	public:
		OptionMenuState(ApplicationState *parent);

		void update() override;

		void buttonHit(OgreBites::Button *button) override;
};

#endif // !OPTIONMENUSTATE_HPP_
