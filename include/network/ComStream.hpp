//
// ComStream.hpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/reseau/include/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Sun Jun  4 17:08:11 2017 Maxime Maisonnas
// Last update Fri Jun  9 14:42:42 2017 Maxime Maisonnas
//

#ifndef COM_STREAM_HPP_
# define COM_STREAM_HPP_

# include <sstream>
# include <string.h>
# include <unistd.h>
# include "Error.hpp"

class             ComStream {
public:
  ComStream();
  ComStream(std::string const &);
  ~ComStream();


  template<typename T>
  ComStream       &operator<<(T const);
  template<typename T>
  ComStream       &operator>>(T &);
  ComStream       &operator>>(std::string &);

  std::string     str(void) const;
  void            str(std::string const &);

private:
  std::string     m_stream;
};

#endif /* end of include guard: COM_STREAM_HPP_ */
