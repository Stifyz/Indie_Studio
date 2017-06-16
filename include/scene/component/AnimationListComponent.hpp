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

#define ANIM_FADE_SPEED 7.5f

class Animation {
	public:
		Animation(Ogre::Entity *entity, const char *name_) : name(name_) {
			state = entity->getAnimationState(name);
			state->setLoop(true);
		}

		std::string name;

		Ogre::AnimationState *state = nullptr;

		bool fadingIn = false;
		bool fadingOut = false;

		Timer timer;
};

class AnimationListComponent {
	using AnimationEndCallback = std::function<void(AnimationListComponent &, const Animation &)>;

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

		Animation *setActiveAnimation(const unsigned int id, const char *animName, const bool reset = false) {
			auto activeAnimIterator = m_activeAnimations.find(id);
			if (activeAnimIterator != m_activeAnimations.end() && activeAnimIterator->second) {
				auto oldAnimIterator = m_animationList.find(activeAnimIterator->second);
				oldAnimIterator->second.fadingIn = false;
				oldAnimIterator->second.fadingOut = true;
			}

			m_activeAnimations[id] = animName;

			if (animName) {
				auto animIterator = m_animationList.find(animName);
				if (animIterator == m_animationList.end()) {
					throw EXCEPTION("Animation not found:", animName);
				}

				animIterator->second.state->setEnabled(true);
				animIterator->second.state->setWeight(0);
				animIterator->second.fadingIn = true;
				animIterator->second.fadingOut = false;
				if (reset)
					animIterator->second.state->setTimePosition(0);
				return &animIterator->second;
			}

			return nullptr;
		}

		bool isAnimationFinished(const char *name, unsigned int percentage = 100) {
			auto animIterator = m_animationList.find(name);
			if (animIterator == m_animationList.end()) {
				throw EXCEPTION("Animation not found:", name);
			}

			Ogre::Real timePos = animIterator->second.state->getTimePosition();
			return timePos == 0 || timePos >= animIterator->second.state->getLength() / percentage * 100;
		}

		const char *getActiveAnimation(const unsigned int id) const {
			return m_activeAnimations.at(id);
		}

		void updateActiveAnimations() {
			for (auto &it : m_activeAnimations) {
				if (!it.second)
					continue;

				Animation &anim = m_animationList.at(it.second);
				if (anim.state->getTimePosition() >= anim.state->getLength() && m_animationEndCallback)
					m_animationEndCallback(*this, anim);

				if (anim.timer.isStarted()) {
					anim.state->addTime(anim.timer.time() / 1000.0);
					anim.timer.reset();
				}
				anim.timer.start();
			}
		}

		void fadeAnimations() {
			for (auto &it : m_animationList) {
				if (it.second.fadingIn) {
					Ogre::Real newWeight = it.second.state->getWeight() + ANIM_FADE_SPEED;
					it.second.state->setWeight(Ogre::Math::Clamp<Ogre::Real>(newWeight, 0, 1));
					if (newWeight >= 1)
						it.second.fadingIn = false;
				}
				else if (it.second.fadingOut) {
					Ogre::Real newWeight = it.second.state->getWeight() - ANIM_FADE_SPEED;
					it.second.state->setWeight(Ogre::Math::Clamp<Ogre::Real>(newWeight, 0, 1));
					if (newWeight <= 0) {
						it.second.state->setEnabled(false);
						it.second.fadingOut = false;
					}
				}
			}
		}

		void setLoop(const char *name, bool loop) { m_animationList.at(name).state->setLoop(loop); }

		void setAnimationEndCallback(const AnimationEndCallback &animationEndCallback) { m_animationEndCallback = animationEndCallback; }

	private:
		std::map<std::string, Animation> m_animationList;

		std::map<unsigned int, const char *> m_activeAnimations;

		AnimationEndCallback m_animationEndCallback;
};

#endif // ANIMATIONLISTCOMPONENT_HPP_
