//
// ComStream.cpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/reseau/src/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Sun Jun  4 17:08:08 2017 Maxime Maisonnas
// Last update Sun Jun 18 16:29:23 2017 Maxime Maisonnas
//

#include "ComStream.hpp"

ComStream::ComStream() {
  m_stream = "";
}

ComStream::ComStream(std::string const &str) {
  m_stream = str;
}

ComStream::~ComStream() {}

template<typename T>
ComStream           &ComStream::operator<<(T const val) {
  std::stringstream tmp;

  tmp << val;
  m_stream += tmp.str() + "\r\r";
  return (*this);
}

template<typename T>
ComStream           &ComStream::operator>>(T &val) {
  std::stringstream tmp;
  std::string       sub;
  size_t            pos = m_stream.find_first_of("\r\r", 0);

  if (m_stream.length() <= 1)
    throw Error("stream is empty");
  sub = m_stream.substr(0, m_stream.find_first_of("\r\r", 0));
  tmp << sub;
  tmp >> val;
  m_stream.erase(0, pos + 2);
  return (*this);
}

ComStream           &ComStream::operator>>(std::string &val) {
  std::string       sub;
  size_t            pos = m_stream.find_first_of("\r\r", 0);

  if (m_stream.length() <= 1)
    throw Error("stream is empty");
  val = m_stream.substr(0, m_stream.find_first_of("\r\r", 0));
  m_stream.erase(0, pos + 2);
  return (*this);
}


std::string   ComStream::str(void) const {
  return (m_stream);
}

void   ComStream::str(std::string const &str) {
  m_stream = str;
}

/* Instanciation des templates */
template ComStream &ComStream::operator<<(int const);
template ComStream &ComStream::operator<<(unsigned int const);
template ComStream &ComStream::operator<<(float const);
template ComStream &ComStream::operator<<(double const);
template ComStream &ComStream::operator<<(char const);
template ComStream &ComStream::operator<<(std::string const);

template ComStream &ComStream::operator>>(int &);
template ComStream &ComStream::operator>>(unsigned int &);
template ComStream &ComStream::operator>>(float &);
template ComStream &ComStream::operator>>(double &);
template ComStream &ComStream::operator>>(char &);
