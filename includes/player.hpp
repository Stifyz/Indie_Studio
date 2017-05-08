/*
** Loris
*/

#ifndef _PLAYER_HPP_
# define  _PLAYER_HPP_

# include <iostream>

typedef struct	s_pos
{
  int		x;
  int		y;
  int		z;
}		t_pos;

class	Player
{
public:
  Player(std::string);
  ~Player(){}
  std::string	GetName();
  void		SetName(std::string);
  t_pos		GetPosition();
  void		SetPosition(t_pos);
protected:
  std::string	_player_name;
  t_pos		_pos;
};

#endif /* !_PLAYER_HPP */
