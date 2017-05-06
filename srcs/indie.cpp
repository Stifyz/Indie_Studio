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

void		Indie::SetMap()
{
  std::stringstream	tmp;
  std::string		buf;
  std::ifstream		map_one;
  std::ifstream		map_two;
  std::ifstream		map_three;

  map_one.open("ressources/map_1.txt");
  map_two.open("ressources/map_2.txt");
  map_three.open("ressources/map_3.txt");
  while (getline(map_one, buf))
    tmp << buf << std::endl;
  _map_one = tmp.str();
  tmp.str("");
  while (getline(map_two, buf))
    tmp << buf << std::endl;
  _map_two = tmp.str();
  tmp.str("");
  while (getline(map_three, buf))
    tmp << buf << std::endl;
  _map_three = tmp.str();
}
