/*
** Loris
*/

#include "indie.hpp"
#include "player.hpp"

int	main()
{
  Indie	New("New game");
  Player Tmp("Loris");

  Tmp.GetPosition();
  std::cout << New.GetMap("_map_two");
  return (0);
}
