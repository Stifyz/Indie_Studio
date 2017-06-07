
#ifndef MENU_HPP_
# define MENU_HPP_

#include "Application.hpp"
#include "OgreData.hpp"

class   Ui
{
	public:
		Ui(OgreBites::TrayManager *trayManager);
		~Ui();

		enum MenuType {
			Main,
			Game,
			Setting,
			HowToPlay
		};

		void launch(const MenuType m_menuType);
		void clear() const;
		void refresh();

		void setStart();
		void setGame();
		void setSettings();
		void setHowToPlay();

		typedef void (Ui::*MenuPtr)();

	private:
		const shared_ptr<OgreBites::TrayManager> m_uiManager = nullptr;

		MenuType m_actMenu;

		static std::map<Ui::MenuType, MenuPtr> m_menu = {
			{MenuType::Main, &Ui::setMain},
			{MenuType::Game, &Ui::setGame},
			{MenuType::Settings, &Ui::setSettings},
			{MenuType::HowToPlay, &Ui::setHowToPlay}
		}
};

#endif /* MENU_HPP_ */
