/*
** Loris
*/

#ifndef _INDIE_HPP_
# define _INDIE_HPP_

#include <iostream>

class	Indie
{
public:
  Indie(std::string);
  ~Indie(){}
  std::string	GetName();
  void		SetName(std::string);
protected:
  std::string	_session_name;
};

#endif /* ! _INDIE_HPP_ */
