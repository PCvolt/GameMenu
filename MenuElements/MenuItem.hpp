//
// Created by PC_volt on 23/09/2023.
//

#ifndef GAMEMENU_MENUITEM_HPP
#define GAMEMENU_MENUITEM_HPP

#include "Position.hpp"
#include "Size.hpp"

#include <functional>
#include <string>

namespace MenuElements
{
class MenuItem // base, virtual
{
  public:
	enum class Orientation
	{
		Horizontal,
		Vertical
	};

	explicit MenuItem(const std::string & name);

	void setOnClick(std::function<void()>);

	void update();

	void setHover(const bool hovered);
	bool isHovered() const;

  private:
	std::string m_name;
	Position m_position;
	Size m_size;
	bool m_canHover;
	bool m_isHovered = false;
	Orientation m_orientation = Orientation::Horizontal;

	std::function<void()> m_onClick;
	bool m_clicked = true;
};
} // namespace MenuElements

#endif // GAMEMENU_MENUITEM_HPP
