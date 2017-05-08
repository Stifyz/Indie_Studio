/*
** Loris
*/

#include "player.hpp"

Player::Player(std::string name)
{
  _player_name = name;
  _pos.x = 0;
  _pos.y = 0;
  _pos.z = 0;
  _is_living = YES;
  _health = 100;
}

std::string	Player::GetName()
{
  return (_player_name);
}

void		Player::SetName(std::string name)
{
  _player_name = name;
}

t_pos		Player::GetPosition()
{
  std::cout << "the player " << _player_name << "is in : ";
  std::cout << _pos.x << " in x, " << _pos.y << " in y and " << _pos.z << " in z.\n";
  return (_pos);
}

void		Player::SetPosition(t_pos new_pos)
{
  _pos.x = new_pos.x;
  _pos.y = new_pos.y;
  _pos.z = new_pos.z;
}

void		Player::IsDead(int life)
{
  _is_living = life;
  if (_is_living == NO)
    std::cout << "The player is dead." << std::endl, exit(0);
  else
    std::cout << "The player is living." << std::endl;
}

int		Player::GetHealth()
{
  return (_health);
}

void		Player::SetHealth(int points)
{
  if (_health + points >= 100)
    _health = 100;
  else if (_health + points <= 0)
    IsDead(1);
  else
    _health = _health + points;
}
