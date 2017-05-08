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
  Tmp.SetHealth(-40);
  Tmp.SetHealth(50);
  Tmp.SetHealth(-400);
  return (0);
}
