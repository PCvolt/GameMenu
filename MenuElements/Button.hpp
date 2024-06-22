//
// Created by PC_volt on 23/09/2023.
//

#ifndef GAMEMENU_BUTTON_HPP
#define GAMEMENU_BUTTON_HPP

#include "MenuItem.hpp"

#include <functional>

namespace MenuElements
{
class Button : public MenuItem
{
  public:
	explicit Button(const std::string & name);

  private:
	std::function<void()> callback;
};
} // namespace MenuElements

#endif // GAMEMENU_BUTTON_HPP
