/*
 * =====================================================================================
 *
 *       Filename:  Window.cpp
 *
 *    Description:
 *
 *        Created:  25/05/2017 01:53:00
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Exception.hpp"
#include "Window.hpp"

Window::Window() {
	m_device.reset(irr::createDevice(irr::video::EDT_OPENGL,
	                                 irr::core::dimension2d<irr::u32>(800, 600), 32));
	if (!m_device)
		throw EXCEPTION("Failed to create Irrlicht device");

	m_device->setWindowCaption(L"Indie Studio: Gauntlet");
	m_driver = m_device->getVideoDriver();
}

void Window::clear() {
	m_driver->beginScene(true, true, irr::video::SColor(50, 153, 204, 255));
}

void Window::refresh() {
	m_driver->endScene();
}

