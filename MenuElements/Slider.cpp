//
// Created by PC_volt on 23/09/2023.
//

#include "Slider.hpp"

namespace MenuElements
{
Slider::Slider(const std::string & name, const std::pair<int, int> range) : MenuItem(name),
                                                                            m_range(range),
                                                                            m_value(range.first)
{
}

Slider::Slider(const std::string & name, const std::pair<int, int> range, int defaultValue)
        : MenuItem(name), m_range(range), m_value(defaultValue)
{
}

void Slider::setValue(const int value)
{
    m_value = value;
}

void Slider::incrementValue(const int increment)
{
    m_value += increment;
}

void Slider::decrementValue(const int decrement)
{
    m_value -= decrement;
}
}