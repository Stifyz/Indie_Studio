/*
 * =====================================================================================
 *
 *       Filename:  CameraFactory.hpp
 *
 *    Description:
 *
 *        Created:  08/06/2017 20:50:55
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef CAMERAFACTORY_HPP_
#define CAMERAFACTORY_HPP_

#include "SceneObject.hpp"

class CameraFactory {
	public:
		static SceneObject create(SceneObject &objectToWatch);
};

#endif // CAMERAFACTORY_HPP_
