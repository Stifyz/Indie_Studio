/*
 * =====================================================================================
 *
 *       Filename:  RoomLoader.hpp
 *
 *    Description:
 *
 *        Created:  12/01/2015 15:04:54
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ROOMLOADER_HPP_
#define ROOMLOADER_HPP_

#include "ResourceLoader.hpp"

class RoomLoader : public ResourceLoader {
	public:
		void load(const char *xmlFilename, ResourceHandler &handler) override;

		void loadRoom(const std::string &name, ResourceHandler &handler);
};

#endif // ROOMLOADER_HPP_
