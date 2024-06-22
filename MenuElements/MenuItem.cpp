//
// Created by PC_volt on 23/09/2023.
//

#include "MenuItem.hpp"

namespace MenuElements
{

MenuItem::MenuItem(const std::string & name)
	: m_name(name)
{
	// give a callback
}

void MenuItem::setOnClick(std::function<void()> onClick)
{
	m_onClick = onClick;
}

void MenuItem::update()
{
	if (m_clicked)
	{
		m_onClick();
		// play sound
		// render
		m_clicked = false; // disable immediately to avoid being clicked multiple
						   // times in a row?
	}
	else
	{
		// render
	}
}

void MenuItem::setHover(const bool hovered)
{
	m_isHovered = hovered;
}

bool MenuItem::isHovered() const
{
	return m_isHovered;
}

} // namespace MenuElements
