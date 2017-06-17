//
// RingBuffer.hpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/reseau/include/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Sat Jun 17 12:33:33 2017 Maxime Maisonnas
// Last update Sat Jun 17 23:40:28 2017 Maxime Maisonnas
//

#ifndef RINGBUFFER_HPP_
# define RINGBUFFER_HPP_

# ifndef BUF_SIZE
#  define BUF_SIZE 8192
# endif /* !BUF_SIZE */

# include <string.h>

# include "Error.hpp"

class           RingBuffer {
public:
  RingBuffer();
  ~RingBuffer();

  void          add(char *, size_t const);
  std::string   get(void);

private:
  char          m_buffer[BUF_SIZE];
  char          *m_rPtr;
  char          *m_wPtr;
};

#endif /* end of include guard: RINGBUFFER_HPP_ */
