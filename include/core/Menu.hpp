
#ifndef MENU_HPP_
# define MENU_HPP_

#include "Application.hpp"
#include "OgreData.hpp"
#include <array>

class   Ui
{
public:
  
  enum	MenuType
    {
      START,
      SETTINGS,
      HOWTOPLAY,
      QUIT
    };
  
  Ui(OgreBites::TrayManager *trayManager);
  ~Ui();
  void	refresh(MenuType m_menuType);
  void	start();
  void	settings();
  void	howtoplay();
  
private:
  OgreBites::TrayManager	*m_uiManager = nullptr;
  typedef void (Ui::*MenuPtr)();
  std::array<Ui::MenuType, 3>     m_menuType;
  
  MenuPtr m_menuptr[3];
};

#endif /* MENU_HPP_ */
