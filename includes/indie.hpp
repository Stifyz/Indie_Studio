/*
** Loris
*/

#ifndef _INDIE_HPP_
# define _INDIE_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

class	Indie
{
public:
  Indie(std::string);
  ~Indie(){}
  std::string	GetName();
  void		SetName(std::string);
  std::string	GetMap(std::string);
  void		SetMap();
protected:
  std::string	_session_name;
  std::string	_map_one;
  std::string	_map_two;
  std::string	_map_three;
};

#endif /* ! _INDIE_HPP_ */
