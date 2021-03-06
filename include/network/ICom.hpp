//
// ICom.hpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/reseau/include/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Sat May 20 17:43:18 2017 Maxime Maisonnas
// Last update Sun Jun 18 17:56:28 2017 Maxime Maisonnas
//

#ifndef ICOM_HPP_
# define ICOM_HPP_

/* Include socket */
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>

# include <string>

# include "ComStream.hpp"

namespace com {
  enum TYPE {
    POSITION = 0,
    DIRECTION = 1,
    CHAT = 2,
    NEW_PERSO = 3
  };
};

typedef struct        s_socket {
  struct protoent			*pe;
  struct sockaddr_in  s_in;
  socklen_t           size;
  int                 fd;
  std::string         ip;
  int                 port;
}                     t_socket;

/* Interface pour communiquer via le réseau */
class ICom {
public:
  virtual ~ICom() = default;

  virtual void serialize(ComStream &) const = 0;
  virtual void deserialize(ComStream &) = 0;
};

#endif /* end of include guard: ICOM_HPP_ */
