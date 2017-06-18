//
// Packet.hpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/include/network/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Sun Jun 18 15:00:44 2017 Maxime Maisonnas
// Last update Sun Jun 18 22:50:17 2017 Maxime Maisonnas
//

#ifndef PACKET_HPP_
# define PACKET_HPP_

#include "ICom.hpp"

namespace com {
  class Packet {
  public:
    Packet() {}
    Packet(unsigned int const id, com::TYPE const type, ICom const &elem) {
      set(id, type, elem);
    }

    void init(void) { m_stream.str(""); }

    void set(unsigned int const id, com::TYPE const type, ICom const &elem) {
      ComStream tmp;
      std::string tmps;

      elem.serialize(tmp);
      m_stream.str("");
      m_stream << id << (int)type;
      tmps = m_stream.str() + tmp.str();
      m_stream.str(tmps);
    }

    unsigned int getId() const {
      int id;
      ComStream tmp(m_stream.str());

      tmp >> id;
      return (id);
    }

    com::TYPE getType() const {
      int id;
      int type;
      ComStream tmp(m_stream.str());

      tmp >> id >> type;
      return (static_cast<com::TYPE>(type));
    }

    ComStream str() const { return (m_stream); }

    void str(std::string const &str) {
      m_stream.str(str);
    }

    ComStream &getData() {
      int id;
      int type;

      m_stream >> id >> type;
      return (m_stream);
    }


  private:
    ComStream m_stream;
  };
};

#endif /* end of include guard: PACKET_HPP_ */
