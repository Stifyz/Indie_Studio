/*
 * =====================================================================================
 *
 *       Filename:  AnimationListComponent.hpp
 *
 *    Description:
 *
 *        Created:  29/05/2017 11:31:45
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ANIMATIONLISTCOMPONENT_HPP_
#define ANIMATIONLISTCOMPONENT_HPP_

#include <map>

#include <OgreEntity.h>
#include <OgreAnimationState.h>

#include "Exception.hpp"
#include "Timer.hpp"

class Animation {
	public:
		Animation(Ogre::Entity *entity, const char *animName) {
			state = entity->getAnimationState(animName);
			state->setLoop(true);
		}

		Ogre::AnimationState *state = nullptr;

		bool fadingIn = false;
		bool fadingOut = false;

		Timer timer;
};

class AnimationListComponent {
	public:
		void add(Ogre::Entity *entity, const char *animName) {
			m_animationList.emplace(animName, Animation{entity, animName});
		}

		void enableAnimation(const char *animName) {
			auto animIterator = m_animationList.find(animName);
			if (animIterator == m_animationList.end()) {
				throw EXCEPTION("Animation not found:", animName);
			}

			animIterator->second.state->setEnabled(true);
		}

		void disableAnimation(const char *animName) {
			auto animIterator = m_animationList.find(animName);
			if (animIterator == m_animationList.end()) {
				throw EXCEPTION("Animation not found:", animName);
			}

			animIterator->second.state->setEnabled(false);
		}

		void setupActiveAnimation(const unsigned int id, const char *animName, const bool reset = false) {
			auto animIterator = m_animationList.find(animName);
			if (animIterator == m_animationList.end()) {
				throw EXCEPTION("Animation not found:", animName);
			}

			if (!animName) {
				animIterator->second.fadingIn = false;
				animIterator->second.fadingOut = true;
			}

			m_activeAnimations.emplace(id, animName);

			if (animName) {
				animIterator->second.state->setEnabled(true);
				animIterator->second.state->setWeight(0);
				animIterator->second.fadingIn = true;
				animIterator->second.fadingOut = false;
				if (reset)
					animIterator->second.state->setTimePosition(0);
			}
		}

		void updateActiveAnimations() {
			for (auto &it : m_activeAnimations) {
				Animation &anim = m_animationList.at(it.second);
				// anim.state->addTime(6);
				if (anim.timer.isStarted()) {
					anim.state->addTime(anim.timer.time());
					anim.timer.reset();
				}
				anim.timer.start();
			}
		}

		// void updateActiveAnimations(unsigned int id) {
		// 	auto animIterator = m_animationList.find(animName);
		// 	if (animIterator == m_animationList.end()) {
		// 		throw EXCEPTION("Animation ");
		// 	}
        //
		// 	 animIterator->second->anim()
		// }

	private:
		std::map<const char *, Animation> m_animationList;

		std::map<unsigned int, const char *> m_activeAnimations;
};

#endif // ANIMATIONLISTCOMPONENT_HPP_
