/*
** Loris
*/

#include "indie.hpp"

int	main()
{
  Indie	New("New game");

  New.SetMap();
  std::cout << New.GetMap("_map_two");
  return (0);
}
