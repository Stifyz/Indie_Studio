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

std::string	Indie::GetMap(std::string search)
{
  if (strcmp("_map_one", search.c_str()) == 0)
    return (_map_one);
  else if (strcmp("_map_two", search.c_str()) == 0)
    return (_map_two);
  else if (strcmp("_map_three", search.c_str()) == 0)
    return (_map_three);
  else
    return (NULL);
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
