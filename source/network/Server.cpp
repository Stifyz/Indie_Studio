//
// Server.cpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/source/network/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Sun Jun 18 00:53:21 2017 Maxime Maisonnas
// Last update Sun Jun 18 16:36:16 2017 Maxime Maisonnas
//

#include "Server.hpp"

Server  *serv = nullptr;

void    myFctStopServer(int sig) {
  (void)sig;
  if (!serv)
    exit(0);
  serv->quit();
  exit(0);
}

Server::Server(bool const listenStandardInput)
              : m_listenStandardInput(listenStandardInput) {
  m_sock.fd = -1;
  m_buf = new RingBuffer();
  serv = this;
  std::signal(SIGINT, myFctStopServer);
  init();
}

Server::~Server() {
  quit();
}

void    Server::quit(void) {
  if (m_sock.fd != -1)
    close(m_sock.fd);
  for (std::vector<t_socket>::iterator it = m_clients.begin(); it != m_clients.end(); it++) {
    if (it->fd != -1) {
      shutdown(it->fd, 2);
      close(it->fd);
    }
  }
  if (m_buf != nullptr) {
    delete m_buf;
    m_buf = nullptr;
  }
}

void              Server::getIp(void) {
  struct ifaddrs  *addrs = NULL;
  struct ifaddrs  *tmp = NULL;
  bool            found = false;
  std::string     ip;

  if (getifaddrs(&addrs) == -1)
    throw NetErr("can't get server's ip");
  tmp = addrs;
  while (tmp && !found) {
    if (tmp->ifa_addr && tmp->ifa_addr->sa_family == AF_INET) {
      struct sockaddr_in *pAddr = (struct sockaddr_in *)tmp->ifa_addr;
      ip = inet_ntoa(pAddr->sin_addr);
      if (ip != "127.0.0.1") {
        m_sock.ip = ip;
        found = true;
      }
    }
    tmp = tmp->ifa_next;
  }
  if (!found)
    throw NetErr("can't get server's ip");
  freeifaddrs(addrs);
}

void    Server::init() {
  if (!(m_sock.pe = getprotobyname("TCP")))
    throw NetErr("can not get protocol");
  if ((m_sock.fd = socket(AF_INET, SOCK_STREAM, m_sock.pe->p_proto)) == -1)
    throw NetErr("can not open socket");
  m_sock.s_in.sin_family = AF_INET;
  m_sock.s_in.sin_port = 0;
  m_sock.s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(m_sock.fd, (struct sockaddr *)&m_sock.s_in, sizeof(m_sock.s_in)) == -1)
    throw NetErr("can not bind port");
  if (listen(m_sock.fd, 42) == -1)
    throw NetErr("can not listen");
  m_sock.size = sizeof(m_sock.s_in);
  if (getsockname(m_sock.fd, (struct sockaddr *)&m_sock.s_in, &m_sock.size) == -1)
    throw NetErr("can not getsockname");
  getIp();
  m_sock.port = ntohs(m_sock.s_in.sin_port);
  std::cout << "Connection's ip : '" << m_sock.ip << "'\n";
  std::cout << "Connection's port : '" << m_sock.port << "'\n";
}

void    Server::addConnection(void) {
  t_socket  client;

  client.size = sizeof(client.s_in);
  client.fd = accept(m_sock.fd, (struct sockaddr *)&client.s_in, &client.size);
  if (client.fd == -1)
    throw NetErr("can not accept client");
  client.ip = inet_ntoa(client.s_in.sin_addr);
  std::cerr << "Client " << m_clients.size() + 1 << " is connected (ip address : "
            << client.ip << ")\n";
  m_clients.push_back(client);
  dprintf(client.fd, "%d\r\r\r\n", static_cast<int>(m_clients.size()));
}

void        Server::mySelect(void) {
  struct timeval  tv;

  tv.tv_sec = TIME_OUT_S;
  tv.tv_usec = TIME_OUT_U;
  initFdSet();
  if (select(getFdSelect(), &m_fdR, NULL, NULL, &tv) == -1)
    throw NetErr("can not select");
  if (FD_ISSET(m_sock.fd, &m_fdR))
    addConnection();
}

void    Server::initFdSet(void) {
  FD_ZERO(&m_fdR);
  FD_ZERO(&m_fdW);
  FD_SET(m_sock.fd, &m_fdR);
  if (m_listenStandardInput)
    FD_SET(0, &m_fdR);
  for (std::vector<t_socket>::const_iterator it = m_clients.begin(); it != m_clients.end(); it++) {
    if (it->fd != -1)
      FD_SET(it->fd, &m_fdR);
  }
}

int     Server::getFdSelect(void) const {
  int   max = 0;

  for (std::vector<t_socket>::const_iterator it = m_clients.begin(); it != m_clients.end(); it++) {
    if (it->fd > max)
      max = it->fd;
  }
  if (m_sock.fd > max)
    return (m_sock.fd + 1);
  return (max + 1);
}

bool        Server::checkAlive(int &fd, int const &index) {
  int       err = 0;
  socklen_t l = sizeof(err);

  if (getsockopt(fd, SOL_SOCKET, SO_ERROR, &err, &l) == -1)
    throw NetErr("system error");
  if (err != 0) {
    std::cerr << "Client " << index << " has disconnected\n";
    close(fd);
    fd = -1;
    return (false);
  }
  return (true);
}

void          Server::send(com::Packet const packet) {
  size_t      i = 1;

  mySelect();
  for (std::vector<t_socket>::iterator it = m_clients.begin(); it != m_clients.end(); it++) {
    if (it->fd != -1) {
      if (checkAlive(it->fd, i))
        dprintf(it->fd, "%s\r\n", packet.str().str().c_str());
    }
    i++;
  }
}

bool          Server::get(com::Packet &packet) {
  size_t      i = 1;
  size_t      r = 0;
  char        buff[BUFF_SIZE];
  ComStream   ss;

  mySelect();
  for (std::vector<t_socket>::iterator it = m_clients.begin(); it != m_clients.end(); it++) {
    if (it->fd != -1) {
      if (FD_ISSET(it->fd, &m_fdR)) {
        try {
          checkAlive(it->fd, i);
          if ((r = recv(it->fd, buff, BUFF_SIZE, 0)) == 0)
            throw Stop();
          m_buf->add(buff, r);
          packet.str(m_buf->get());
          return (true);
        } catch (...) {
          std::cerr << "Client " << i << " has disconnected\n";
          close(it->fd);
          it->fd = -1;
        }
      }
    }
    i++;
  }
  return (false);
}

bool          Server::get(com::Packet &packet, chat::TextMsg &elem) {
  size_t      i = 1;
  size_t      r = 0;
  char        buff[BUFF_SIZE];
  ComStream   ss;

  mySelect();
  for (std::vector<t_socket>::iterator it = m_clients.begin(); it != m_clients.end(); it++) {
    if (it->fd != -1) {
      if (FD_ISSET(it->fd, &m_fdR)) {
        try {
          checkAlive(it->fd, i);
          if ((r = recv(it->fd, buff, BUFF_SIZE, 0)) == 0)
            throw Stop();
          m_buf->add(buff, r);
          packet.str(m_buf->get());
          return (true);
        } catch (...) {
          std::cerr << "Client " << i << " has disconnected\n";
          close(it->fd);
          it->fd = -1;
        }
      }
    }
    i++;
  }
  if (m_listenStandardInput && FD_ISSET(0, &m_fdR)) {
    if ((r = read(0, buff, BUFF_SIZE)) == 0)
      throw Error("invalid input");
    m_buf->add(buff, r);
    elem = chat::TextMsg(id(), m_buf->get(), chat::PUBLIC);
    packet.set(id(), com::CHAT, elem);
    return (true);
  }
  return (false);
}
