//
// Created by PC_volt on 23/09/2023.
//

#ifndef GAMEMENU_LABELLEDITEM_HPP
#define GAMEMENU_LABELLEDITEM_HPP

#include "Label.hpp"

namespace MenuElements
{
class LabelledItem : public MenuItem
{
  public:
	LabelledItem(const std::string & name, std::pair<Label, MenuItem> labelAndElement);

  private:
	std::pair<Label, MenuItem> m_labelAndElement;
};
} // namespace MenuElements

#endif // GAMEMENU_LABELLEDITEM_HPP
