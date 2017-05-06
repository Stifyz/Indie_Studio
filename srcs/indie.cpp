/*
** Loris
*/

#include "indie.hpp"

Indie::Indie(std::string name)
{
  _session_name = name;
}

std::string	Indie::GetName()
{
  return (_session_name);
}

void		Indie::SetName(std::string new_name)
{
  _session_name = new_name;
}
