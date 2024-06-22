//
// Created by PC_volt on 23/09/2023.
//

#ifndef GAMEMENU_MENUITEMLIST_HPP
#define GAMEMENU_MENUITEMLIST_HPP

#include "MenuItem.hpp"

#include <vector>

namespace MenuElements
{
/**
 * MenuItemList is the element contained by Window, and it regroups all the
 * elements that we will navigate through.
 */
class MenuItemList : public MenuItem
{
  public:
	enum class Orientation
	{
		Horizontal,
		Vertical
	};

	enum class Direction
	{
		Previous,
		Next
	};

	explicit MenuItemList(const std::string & name);

	void appendElementToList(const MenuItem & element);

	void moveCursor(const Direction direction);

	void update();

	std::vector<MenuItem> getItemList() const;

	int getCursorIndex() const;

  private:
	std::vector<MenuItem> m_itemList;
	Orientation m_orientation = Orientation::Vertical;
	int m_cursorIndex = 0;
};
} // namespace MenuElements

#endif // GAMEMENU_MENUITEMLIST_HPP
