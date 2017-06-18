#ifndef VICTORYSTATE_HPP_
#define VICTORYSTATE_HPP_

#include <OgreCamera.h>

#include "ApplicationState.hpp"
#include "Background.hpp"

class VictoryState : public ApplicationState {
	public:
		VictoryState();

		void update() override;

		void buttonHit(OgreBites::Button *button) override;

	private:
		Background m_background;

		Ogre::Camera *m_camera;
};

#endif // VICTORYSTATE_HPP_
