#ifndef GAMEOVERSTATE_HPP_
#define GAMEOVERSTATE_HPP_

#include <OgreCamera.h>

#include "ApplicationState.hpp"
#include "Background.hpp"

class SplashScreenState : public ApplicationState {
	public:
		SplashScreenState();

		void update() override;

		void buttonHit(OgreBites::Button *button) override;

	private:
		Background m_background;

		Ogre::Camera *m_camera;
};

#endif // !SPLASHSCREEN_HPP_
