//
// VectorCom.hpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/include/network/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Sun Jun 18 17:41:37 2017 Maxime Maisonnas
// Last update Sun Jun 18 17:56:26 2017 Maxime Maisonnas
//

#ifndef VECTORCOM_HPP_
# define VECTORCOM_HPP_

# include "ICom.hpp"

class     VectorCom : public ICom {
public:
  VectorCom() {}
  VectorCom(int const characterId, Ogre::Vector3 const &vec) { set(characterId, vec); };

  void set(int const characterId, Ogre::Vector3 const &vec) {
    m_characterId = characterId;
    m_x = vec.x;
    m_y = vec.y;
    m_z = vec.z;
  }

  virtual void serialize(ComStream &cs) const {
    cs << m_characterId << m_x << m_y << m_z;
  }
  virtual void deserialize(ComStream &cs) {
    cs >> m_characterId >> m_x >> m_y >> m_z;
  }

  int m_characterId;
  double m_x;
  double m_y;
  double m_z;
};

#endif /* end of include guard: VECTORCOM_HPP_ */
