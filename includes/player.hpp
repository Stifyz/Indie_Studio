/*
** Loris
*/

#ifndef _PLAYER_HPP_
# define  _PLAYER_HPP_

# include <iostream>
# include "indie.hpp"
typedef struct	s_pos
{
  int		x;
  int		y;
  int		z;
}		t_pos;

enum	IsLiving
  {
    YES = 0,
    NO = 1
  };

class	Player : public Indie
{
public:
  Player(std::string);
  ~Player(){}
  std::string	GetName();
  void		SetName(std::string);
  t_pos		GetPosition();
  void		SetPosition(t_pos);
  void		IsDead(int);
  int		GetHealth();
  void		SetHealth(int);
protected:
  std::string	_player_name;
  t_pos		_pos;
  bool		_is_living;
  int		_health;
};

#endif /* !_PLAYER_HPP */
