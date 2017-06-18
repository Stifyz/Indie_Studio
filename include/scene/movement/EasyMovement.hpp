/*
 * =====================================================================================
 *
 *       Filename:  EasyMovement.hpp
 *
 *    Description:
 *
 *        Created:  18/06/2017 06:33:04
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EASYMOVEMENT_HPP_
#define EASYMOVEMENT_HPP_

#include <functional>

#include "Movement.hpp"

class EasyMovement : public Movement {
	public:
		EasyMovement(const std::function<void(SceneObject &)> &func) : m_func(func) {}

		void process(SceneObject &object) override {
			m_func(object);
		}

	private:
		std::function<void(SceneObject &)> m_func;
};

#endif // EASYMOVEMENT_HPP_
