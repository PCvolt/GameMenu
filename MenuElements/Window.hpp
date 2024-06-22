//
// Created by PC_volt on 23/09/2023.
//

#ifndef GAMEMENU_WINDOW_HPP
#define GAMEMENU_WINDOW_HPP

#include "MenuItemList.hpp"

namespace MenuElements
{
/**
 * A Window is the top-most unit where we group elements through a list.
 * Only one Window can be active at a time, and when multiple windows are
 * stacked, the top-most window is the active one.
 */
class Window : public MenuItem
{
  public:
	explicit Window(const std::string & name, const MenuItemList & elementList);
	~Window();
	void assignElementList(const MenuItemList & elementList);

  private:
	MenuItemList m_elementList;
	bool m_isOnTop;
	Window * m_parentWindow;
};
} // namespace MenuElements

#endif // GAMEMENU_WINDOW_HPP
