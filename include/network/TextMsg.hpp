//
// class1.hpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/reseau/include/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Sun Jun  4 15:13:20 2017 Maxime Maisonnas
// Last update Sun Jun 18 22:16:24 2017 Maxime Maisonnas
//

#ifndef CLASS_1_HPP_
# define CLASS_1_HPP_

# include <iostream>
# include <sstream>
# include "ICom.hpp"

namespace chat {
  enum    CHANNEL {
    PUBLIC = 0,
    PRIVATE = 1
  };

  class             TextMsg : public ICom {
  public:
    TextMsg(int const, std::string const &, CHANNEL const, int const idTarget = -1);
    TextMsg         &operator=(TextMsg const &);

    virtual void    serialize(ComStream &ss) const;
    virtual void    deserialize(ComStream &ss);

    std::string     getMsg(void) const;

    unsigned int    m_id;
    std::string     m_msg;
    int             m_chan;
    int             m_idTarget;
  };
};

#endif /* end of include guard: CLASS_1_HPP_ */
