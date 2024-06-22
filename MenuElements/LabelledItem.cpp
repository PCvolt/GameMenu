//
// Created by PC_volt on 23/09/2023.
//

#include "LabelledItem.hpp"

namespace MenuElements
{
LabelledItem::LabelledItem(const std::string & name, std::pair<Label, MenuItem> labelAndElement)
	: MenuItem(name),
	  m_labelAndElement(labelAndElement)
{
}
} // namespace MenuElements
