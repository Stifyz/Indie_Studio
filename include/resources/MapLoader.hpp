/*
 * =====================================================================================
 *
 *       Filename:  MapLoader.hpp
 *
 *    Description:
 *
 *        Created:  12/01/2015 15:04:54
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAPLOADER_HPP_
#define MAPLOADER_HPP_

#include "ResourceLoader.hpp"

class MapLoader : public ResourceLoader {
	public:
		void load(const char *xmlFilename, ResourceHandler &handler) override;

		void loadMap(const std::string &name, ResourceHandler &handler);
};

#endif // MAPLOADER_HPP_
