//
// TextMsg.cpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/reseau/src/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Sat Jun 17 18:40:39 2017 Maxime Maisonnas
// Last update Sun Jun 18 20:42:39 2017 Maxime Maisonnas
//

#include "TextMsg.hpp"
namespace chat {
  TextMsg::TextMsg(int const id, std::string const &msg, CHANNEL const chan, int const idTarget)
                  : m_id(id), m_msg(msg), m_chan(chan), m_idTarget(idTarget) {
    if (chan == PRIVATE && m_idTarget == -1)
      throw Error("invalid target's id");
  }

  TextMsg   &TextMsg::operator=(TextMsg const &original) {
    m_id = original.m_id;
    m_msg = original.m_msg;
    m_chan = original.m_chan;
    m_idTarget = original.m_idTarget;
    return (*this);
  }

  void    TextMsg::serialize(ComStream &ss) const {
    ss << m_id << m_msg << m_chan << m_idTarget;
  }

  void    TextMsg::deserialize(ComStream &ss) {
    ss >> m_id >> m_msg >> m_chan >> m_idTarget;
  }

  std::string   TextMsg::getMsg(void) const {
    std::string msg("");
    std::stringstream ss;

    ss << m_id;
    if (m_id == 0)
      msg = "Server : ";
    else {
      msg = "Client " + ss.str() + " : ";
    }
    msg += m_msg;
    return (msg);
  }

  void    TextMsg::writee(void) {
    std::cout
    << "From : " << m_id
    << "\nMsg : " << m_msg;
    if (m_chan)
      std::cout << "to : " << m_idTarget << '\n';
  }
};
