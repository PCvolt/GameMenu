//
// Created by PC_volt on 23/09/2023.
//

#include "Label.hpp"

namespace MenuElements
{
Label::Label(const std::string & name, const std::string & text) : MenuItem(name), m_text(text)
{
}

void Label::setText(const std::string & text)
{
    m_text = text;
}
}
