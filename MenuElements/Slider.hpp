//
// Created by PC_volt on 23/09/2023.
//

#ifndef GAMEMENU_SLIDER_HPP
#define GAMEMENU_SLIDER_HPP

#include "MenuItem.hpp"

#include <utility>

namespace MenuElements
{
class Slider : public MenuItem
{
public:
    Slider(const std::string & name, const std::pair<int, int> range);
    Slider(const std::string & name, const std::pair<int, int> range, int defaultValue);

    void setValue(const int value);
    void incrementValue(const int increment = 1);
    void decrementValue(const int decrement = 1);
private:
    std::pair<int, int> m_range;
    int m_value;
};

}


#endif //GAMEMENU_SLIDER_HPP
