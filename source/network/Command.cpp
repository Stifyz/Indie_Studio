//
// Command.cpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/reseau/src/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Sat Jun 17 16:12:19 2017 Maxime Maisonnas
// Last update Sun Jun 18 01:35:35 2017 Maxime Maisonnas
//

#include "Command.hpp"

namespace cmd {
  Command::Command(int const id, ACTION const act, DIRECTION const dir, int const idTarget)
                  : m_id(id), m_action(act), m_direction(dir), m_idTarget(idTarget) {
    if (act != MOVE && m_idTarget == -1)
      throw Error("invalid target ID");
  }

  void    Command::serialize(ComStream &cs) const {
    cs << m_id << (int)m_action << (int)m_direction << m_idTarget;
  }

  void    Command::deserialize(ComStream &cs) {
    int   tmpAction;
    int   tmpDirection;

    cs >> m_id >> tmpAction >> tmpDirection >> m_idTarget;
    m_action = static_cast<ACTION>(tmpAction);
    m_direction = static_cast<DIRECTION>(tmpDirection);
  }
};
