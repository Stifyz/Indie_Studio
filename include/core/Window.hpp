/*
 * =====================================================================================
 *
 *       Filename:  Window.hpp
 *
 *    Description:
 *
 *        Created:  25/05/2017 01:52:33
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <functional>
#include <memory>

#include <irrlicht/irrlicht.h>

class Window {
	public:
		Window();

		void clear();

		void refresh();

		bool isOpen() const { return m_device->run() && m_driver; }

		irr::IrrlichtDevice *device() { return m_device.get(); }

	private:
		std::unique_ptr<irr::IrrlichtDevice> m_device{nullptr};

		irr::video::IVideoDriver *m_driver = nullptr;
};

#endif // WINDOW_HPP_
