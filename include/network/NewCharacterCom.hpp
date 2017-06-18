//
// NewCharacterCom.hpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/include/network/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Sun Jun 18 17:58:50 2017 Maxime Maisonnas
// Last update Sun Jun 18 18:15:39 2017 Maxime Maisonnas
//

#ifndef NEWCHARACTERCOM_HPP_
# define NEWCHARACTERCOM_HPP_

# include "ICom.hpp"

class     NewCharacterCom : public ICom {
public:
  NewCharacterCom() {}
  NewCharacterCom(int const characterId, std::string const &character, int const x, int const y) { set(characterId, character, x, y); };

  void set(int const characterId, std::string const &character, int const x, int const y) {
    m_characterId = characterId;
    m_character = character;
    m_x = x;
    m_y = y;
  }

  virtual void serialize(ComStream &cs) const {
    cs << m_characterId << m_character << m_x << m_y;
  }
  virtual void deserialize(ComStream &cs) {
    cs >> m_characterId >> m_character >> m_x >> m_y;
  }

  int m_characterId;
  std::string m_character;
  double m_x;
  double m_y;
};

#endif /* end of include guard: NEWCHARACTERCOM_HPP_ */
