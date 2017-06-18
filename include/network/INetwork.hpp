//
// INetwork.hpp for indie in /home/maxoulak/work/B4/C++/cpp_indie_studio/include/network/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Sun Jun 18 01:40:46 2017 Maxime Maisonnas
// Last update Sun Jun 18 01:54:01 2017 Maxime Maisonnas
//

#ifndef INETWORK_HPP_
# define INETWORK_HPP_

# include "ICom.hpp"
# include "TextMsg.hpp"

class INetwork {
public:
  virtual ~INetwork() = default;

  virtual void send(ICom const &) = 0;
  virtual bool get(ICom &) = 0;
  virtual bool get(chat::TextMsg &) = 0;
  virtual void mySelect(void) = 0;
  virtual int id(void) const = 0;
};

#endif /* end of include guard: INETWORK_HPP_ */
