//
// Client.hpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/reseau/include/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Mon May 22 17:31:31 2017 Maxime Maisonnas
// Last update Sun Jun 18 22:14:11 2017 Maxime Maisonnas
//

#ifndef ENCAPS_CLIENT_HPP_
# define ENCAPS_CLIENT_HPP_

# include <iostream>
# include <string.h>
# include <csignal>

# include "INetwork.hpp"
# include "RingBuffer.hpp"

# ifndef TIME_OUT_CLIENT_S
#  define TIME_OUT_CLIENT_S 0
# endif /* !TIME_OUT_CLIENT_S */

# ifndef TIME_OUT_CLIENT_U
#  define TIME_OUT_CLIENT_U 500
# endif /* !TIME_OUT_CLIENT_U */

class Client : public INetwork {
public:
  Client(int port, bool listenStandardInput = false, std::string const &ip = "");
  virtual ~Client();

  virtual void send(com::Packet const);
  virtual bool get(com::Packet &);
  virtual void mySelect(void);
  virtual unsigned int id(void) const { return (m_id); }
  virtual void loop(bool loop) { m_loop = loop; }
  virtual bool loop(void) const { return m_loop; }
  void quit(void);

private:
  void init(void);
  void checkAlive(void);

  RingBuffer          *m_buf;
  bool                m_listenStandardInput;
  fd_set              m_fdR;
  t_socket            m_sock;
  int                 m_port;
  std::string         m_ip;
  int                 m_id;
  bool                m_loop;
};

#endif /* end of include guard: ENCAPS_CLIENT_HPP_ */
