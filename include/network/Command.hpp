//
// Command.hpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/reseau/include/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Sat Jun 17 15:22:23 2017 Maxime Maisonnas
// Last update Sat Jun 17 16:35:29 2017 Maxime Maisonnas
//

#ifndef COMMAND_HPP_
# define COMMAND_HPP_

# include "ICom.hpp"

namespace cmd {
  enum    ACTION {
    MOVE = 0,
    ATTACK = 1
  };

  enum    DIRECTION {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
  };

  class             Command : public ICom {
  public:
    Command(int const, ACTION const, DIRECTION const, int const idTarget = -1);
    virtual ~Command();

    virtual void    serialize(ComStream &) const;
    virtual void    deserialize(ComStream &);

    int             m_id;
    ACTION          m_action;
    DIRECTION       m_direction;
    int             m_idTarget;
  };
};

#endif /* end of include guard: COMMAND_HPP_ */
