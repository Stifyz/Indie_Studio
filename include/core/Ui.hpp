
#ifndef MENU_HPP_
# define MENU_HPP_

#include <OgreTrays.h>
#include "OgreData.hpp"

#include <map>

class Ui {
public:
  Ui();

  enum MenuType {
    Main,
    Game,
    Settings,
    HowToPlay
  };

  OgreBites::TrayManager *create(const MenuType, Ogre::RenderWindow *);

  void setMain(OgreBites::TrayManager *);
  void setGame(OgreBites::TrayManager *);
  void setSettings(OgreBites::TrayManager *);
  void setHowToPlay(OgreBites::TrayManager *);

  typedef void (Ui::*setMenuFnct)(OgreBites::TrayManager *);

private:
  MenuType m_actMenu;

  const std::map<MenuType, setMenuFnct> m_menu = {
    {MenuType::Main, &Ui::setMain},
    {MenuType::Game, &Ui::setGame},
    {MenuType::Settings, &Ui::setSettings},
    {MenuType::HowToPlay, &Ui::setHowToPlay}
  };
};

#endif /* MENU_HPP_ */

