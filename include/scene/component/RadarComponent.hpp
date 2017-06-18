/*
 * =====================================================================================
 *
 *       Filename:  RadarComponent.hpp
 *
 *    Description:
 *
 *        Created:  19/06/2017 15:44:08
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef RADARCOMPONENT_HPP_
#define RADARCOMPONENT_HPP_

#include "SceneObject.hpp"

class RadarComponent {
	public:
		RadarComponent(const std::string &nameFilter_ = "any", const std::string &typeFilter_ = "any")
			: nameFilter(nameFilter_), typeFilter(typeFilter_) {}

		SceneObject *neareastObject = nullptr;
		float neareastObjectDistance = 0.0f;

		std::string nameFilter;
		std::string typeFilter;
};

#endif // RADARCOMPONENT_HPP_
