//
// Created by PC_volt on 23/09/2023.
//

#ifndef GAMEMENU_LABEL_HPP
#define GAMEMENU_LABEL_HPP

#include "MenuItem.hpp"

#include <string>

namespace MenuElements
{
class Label : public MenuItem
{
public:
    explicit Label(const std::string & name, const std::string & text);

    void setText(const std::string & text);

private:
    std::string m_text;
    int m_maxDisplayedCharacters = 25;
};
}


#endif //GAMEMENU_LABEL_HPP
