/*
 * =====================================================================================
 *
 *       Filename:  Movement.hpp
 *
 *    Description:
 *
 *        Created:  20/04/2017 23:20:34
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MOVEMENT_HPP_
#define MOVEMENT_HPP_

#include "SceneObject.hpp"

#include <OgreVector3.h>
#include <OgreQuaternion.h>

class Movement {
	public:
		virtual ~Movement() = default;

		bool isFinished() const { return m_isFinished; }

		virtual void process(SceneObject &object) = 0;

	protected:
		bool m_isFinished = false;
};

#endif // MOVEMENT_HPP_
