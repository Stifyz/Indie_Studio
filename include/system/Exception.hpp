/*
 * =====================================================================================
 *
 *       Filename:  Exception.hpp
 *
 *    Description:
 *
 *        Created:  20/04/2017 22:31:52
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

#include "Debug.hpp"

#define EXCEPTION(args...) (System::Exception(__LINE__, _FILE_, args))

namespace System {
	class Exception : public std::exception {
		public:
			template<typename... Args>
			Exception(const u16 line, const std::string &filename, Args &&...args) noexcept {
				m_errorMsg = "at " + filename + ":" + std::to_string(line) + ": ";
				m_errorMsg += Debug::makeString(std::forward<Args>(args)...);
			}

		virtual const char *what() const noexcept {
			return m_errorMsg.c_str();
		}

		private:
			std::string m_errorMsg;
	};
}

#endif // EXCEPTION_HPP_
