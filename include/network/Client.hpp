//
// Client.hpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/reseau/include/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Mon May 22 17:31:31 2017 Maxime Maisonnas
// Last update Sun Jun 18 00:52:41 2017 Maxime Maisonnas
//

#ifndef ENCAPS_CLIENT_HPP_
# define ENCAPS_CLIENT_HPP_

# include <iostream>
# include <string.h>
# include <csignal>

# include "ICom.hpp"
# include "Error.hpp"
# include "TextMsg.hpp"
# include "RingBuffer.hpp"

# ifndef TIME_OUT_CLIENT_S
#  define TIME_OUT_CLIENT_S 0
# endif /* !TIME_OUT_CLIENT_S */

# ifndef TIME_OUT_CLIENT_U
#  define TIME_OUT_CLIENT_U 500
# endif /* !TIME_OUT_CLIENT_U */

class                 Client {
public:
  Client(bool listenStandardInput = false);
  ~Client();

  void                init(int port, std::string const &ip = "");
  void                send(ICom const &);
  bool                get(ICom &);
  bool                get(chat::TextMsg &);
  void                quit(void);
  int                 id(void) const { return (m_id); }

protected:
  void                checkAlive(void);
  void                mySelect(void);

  RingBuffer          *m_buf;
  bool                m_listenStandardInput;
  fd_set              m_fdR;
  t_socket            m_sock;
  std::string         m_ip;
  int                 m_port;
  int                 m_id;
};

#endif /* end of include guard: ENCAPS_CLIENT_HPP_ */
