/*
** Loris
*/

#include "indie.hpp"
#include "player.hpp"

int	main()
{
  Player Tmp("Loris");

  Tmp.GetPosition();
  Tmp.SetMap();
  std::cout << Tmp.GetMap("_map_one");
  
  return (0);
}
