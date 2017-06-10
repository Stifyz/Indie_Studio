
#ifndef MENUSTATE_HPP_
# define MENUSTATE_HPP_

#include <OgreTrays.h>
#include <OgreInput.h>

#include "OgreData.hpp"
#include "ApplicationState.hpp"

#include <map>

class MenuState : public OgreBites::InputListener, public ApplicationState {
public:
  MenuState(OgreBites::TrayManager *);

  enum MenuType {
    Main,
    Game,
    Settings,
    HowToPlay
  };

  void loadMenu(const MenuType);
  void setMain();
  void setGame();
  void setSettings();
  void setHowToPlay();

  typedef void (MenuState::*setMenuFnct)();

  bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
  bool keyReleased(const OgreBites::KeyboardEvent& evt) override;
  bool mouseMoved(const OgreBites::MouseMotionEvent& evt) override;
  bool mouseWheelRolled(const OgreBites::MouseWheelEvent& evt) override;
  bool mousePressed(const OgreBites::MouseButtonEvent& evt) override;

  void	update() override;

private:
  MenuType m_actMenu;

  std::shared_ptr<OgreBites::TrayManager> m_menuManager = nullptr;

  const std::map<MenuType, setMenuFnct> m_menu = {
    {MenuType::Main, &MenuState::setMain},
    {MenuType::Game, &MenuState::setGame},
    {MenuType::Settings, &MenuState::setSettings},
    {MenuType::HowToPlay, &MenuState::setHowToPlay}
  };
};

#endif /* MENUSTATE_HPP_ */

