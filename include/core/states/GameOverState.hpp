#ifndef GAMEOVERSTATE_HPP_
#define GAMEOVERSTATE_HPP_

#include <OgreCamera.h>

#include "ApplicationState.hpp"
#include "Background.hpp"

class GameOverState : public ApplicationState {
	public:
		GameOverState();

		void update() override;

		void buttonHit(OgreBites::Button *button) override;

	private:
		Background m_background;

		Ogre::Camera *m_camera;
};

#endif // !GAMEOVERSTATE_HPP_
