//
// RingBuffer.cpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/reseau/src/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Sat Jun 17 12:33:44 2017 Maxime Maisonnas
// Last update Sun Jun 18 03:32:09 2017 Maxime Maisonnas
//

#include "RingBuffer.hpp"

RingBuffer::RingBuffer() {
  memset(m_buffer, 0, BUFF_SIZE);
  m_rPtr = m_buffer;
  m_wPtr = m_buffer;
}

RingBuffer::~RingBuffer() {}

void      RingBuffer::add(char *str, size_t const len) {
  size_t  i = 0;

  while (i < len) {
    *m_wPtr = str[i];
    m_wPtr = &m_buffer[(((size_t)m_wPtr + 1 - (size_t)m_buffer) % BUFF_SIZE)];
    i++;
  }
}

std::string   RingBuffer::get(void) {
  std::string line("");
  int         n = 0;

  while (m_rPtr != m_wPtr) {
    if (*m_rPtr == '\n' && n == 3) {
      m_rPtr = &m_buffer[(((size_t)m_rPtr + 1 - (size_t)m_buffer) % BUFF_SIZE)];
      return (line);
    } else if (*m_rPtr == '\r') {
      line += *m_rPtr;
      m_rPtr = &m_buffer[(((size_t)m_rPtr + 1 - (size_t)m_buffer) % BUFF_SIZE)];
      n++;
    } else {
      line += *m_rPtr;
      m_rPtr = &m_buffer[(((size_t)m_rPtr + 1 - (size_t)m_buffer) % BUFF_SIZE)];
      n = 0;
    }
  }
  return (line);
}
