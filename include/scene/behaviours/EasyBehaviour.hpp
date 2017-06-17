/*
 * =====================================================================================
 *
 *       Filename:  EasyBehaviour.hpp
 *
 *    Description:
 *
 *        Created:  17/06/2017 16:15:05
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EASYBEHAVIOUR_HPP_
#define EASYBEHAVIOUR_HPP_

#include <functional>

#include "Behaviour.hpp"

class EasyBehaviour : public Behaviour {
	public:
		EasyBehaviour(const std::function<void(SceneObject &)> &func) : m_func(func) {}

		void update(SceneObject &object) override {
			m_func(object);
		}

	private:
		std::function<void(SceneObject &)> m_func;
};

#endif // EASYBEHAVIOUR_HPP_
