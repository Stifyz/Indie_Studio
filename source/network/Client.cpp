//
// Client.cpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/reseau/src/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Mon May 22 17:31:35 2017 Maxime Maisonnas
// Last update Sun Jun 18 16:34:06 2017 Maxime Maisonnas
//

#include "Client.hpp"

Client  *cli = nullptr;

void    myFctStopClient(int sig) {
  (void)sig;
  if (!cli)
    exit(0);
  cli->quit();
  exit(0);
}

Client::Client(int port, bool listenStandardInput, std::string const &ip)
              : m_listenStandardInput(listenStandardInput), m_port(port), m_ip(ip) {
  m_sock.fd = -1;
  cli = this;
  m_buf = new RingBuffer();
  std::signal(SIGINT, myFctStopClient);
  init();
}

Client::~Client() {
  quit();
}

void    Client::quit(void) {
  if (m_sock.fd != -1) {
    shutdown(m_sock.fd, 2);
    close(m_sock.fd);
  }
  if (m_buf != nullptr) {
    delete m_buf;
    m_buf = nullptr;
  }
}

void          Client::init() {
  std::string id;
  char        buff[BUFF_SIZE];
  size_t      r = 0;

  if (!(m_sock.pe = getprotobyname("TCP")))
    throw NetErr("could not get protocol");
  if ((m_sock.fd = socket(AF_INET, SOCK_STREAM, m_sock.pe->p_proto)) == -1)
    throw NetErr("could not open socket");
  m_sock.s_in.sin_family = AF_INET;
  m_sock.s_in.sin_port = htons(m_port);
  m_sock.s_in.sin_addr.s_addr = (m_ip == "" ? INADDR_ANY : inet_addr(m_ip.c_str()));
  if (connect(m_sock.fd, (struct sockaddr *)&m_sock.s_in, sizeof(m_sock.s_in)) == -1)
    throw NetErr("could not connect to given port");
  if ((r = recv(m_sock.fd, buff, BUFF_SIZE, 0)) == 0)
    throw Stop();
  m_buf->add(buff, r);
  id = m_buf->get();
  id = id.substr(0, id.find_first_of("\r\r\r", 0));
  m_id = std::stoi(id);
  std::cerr << "Connected (id : " << m_id << ")\n";
}

void        Client::checkAlive(void) {
  int       err = 0;
  socklen_t l = sizeof(err);

  if (getsockopt(m_sock.fd, SOL_SOCKET, SO_ERROR, &err, &l) == -1)
    throw NetErr("system error");
  if (err != 0) {
    close(m_sock.fd);
    m_sock.fd = -1;
    throw NetErr("connection lost");
  }
}

void        Client::mySelect(void) {
  struct timeval  tv;

  tv.tv_sec = TIME_OUT_CLIENT_S;
  tv.tv_usec = TIME_OUT_CLIENT_U;
  FD_ZERO(&m_fdR);
  if (m_listenStandardInput)
    FD_SET(0, &m_fdR);
  FD_SET(m_sock.fd, &m_fdR);
  if (select(m_sock.fd + 1, &m_fdR, NULL, NULL, &tv) == -1)
    throw NetErr("can not select");
}

void          Client::send(com::Packet const packet) {
  checkAlive();
  dprintf(m_sock.fd, "%s\r\n", packet.str().str().c_str());
}

bool          Client::get(com::Packet &packet) {
  size_t      r;
  char        buff[BUFF_SIZE];

  checkAlive();
  try {
    if ((r = recv(m_sock.fd, buff, BUFF_SIZE, 0)) == 0)
      throw Stop();
    m_buf->add(buff, r);
    packet.str(m_buf->get());
  } catch (...) {
    close(m_sock.fd);
    m_sock.fd = -1;
    throw NetErr("connection lost");
  }
  return (true);
}

bool          Client::get(com::Packet &packet, chat::TextMsg &elem) {
  ComStream   ss;
  size_t      r = 0;
  char        buff[BUFF_SIZE];

  checkAlive();
  mySelect();
  if (m_listenStandardInput) {
    if (FD_ISSET(0, &m_fdR)) {
      if ((r = read(0, buff, BUFF_SIZE)) == 0)
        throw Error("invalid input");
      m_buf->add(buff, r);
      elem = chat::TextMsg(m_id, m_buf->get(), chat::PUBLIC);
      packet.set(m_id, com::CHAT, elem);
      send(packet);
      return (false);
    }
  }
  try {
    if (FD_ISSET(m_sock.fd, &m_fdR)) {
      if ((r = recv(m_sock.fd, buff, BUFF_SIZE, 0)) == 0)
        throw Stop();
      m_buf->add(buff, r);
      packet.str(m_buf->get());
      return (true);
    }
  } catch (...) {
    close(m_sock.fd);
    m_sock.fd = -1;
    throw NetErr("connection lost");
  }
  return (false);
}
