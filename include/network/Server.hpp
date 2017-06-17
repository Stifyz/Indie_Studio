//
// Server.hpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/include/network/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Sun Jun 18 00:53:06 2017 Maxime Maisonnas
// Last update Sun Jun 18 00:56:45 2017 Maxime Maisonnas
//

#ifndef ENCAPS_SERVER_HPP_
# define ENCAPS_SERVER_HPP_

# include <iostream>
# include <list>
# include <vector>
# include <thread>
# include <csignal>
# include <string.h>
# include <stdio.h>

# include <sys/types.h>
# include <ifaddrs.h>

# include "TextMsg.hpp"
# include "RingBuffer.hpp"

# ifndef TIME_OUT_S
#  define TIME_OUT_S 0
# endif /* !TIME_OUT_S */

# ifndef TIME_OUT_U
#  define TIME_OUT_U 50
# endif /* !TIME_OUT_U */

class                   Server {
public:
  Server(bool const listenStandardInput = false);
  ~Server();

  void                  init();
  void                  send(ICom const &elem);
  bool                  get(ICom &elem);
  bool                  get(chat::TextMsg &elem);
  void                  quit(void);
  int                   id(void) const { return (0); }

protected:
  void                  getIp(void);
  void                  addConnection(void);
  void                  mySelect(void);
  void                  initFdSet(void);
  int                   getFdSelect(void) const;
  bool                  checkAlive(int &, int const &);

  RingBuffer            *m_buf;
  int                   m_port;
  bool                  m_listenStandardInput;
  t_socket              m_sock;
  std::vector<t_socket> m_clients;
  fd_set                m_fdR;
  fd_set                m_fdW;
};

#endif /* end of include guard: ENCAPS_SERVER_HPP_ */
