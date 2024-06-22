//
// Created by PC_volt on 24/09/2023.
//

#ifndef GAMEMENU_SELECT_HPP
#define GAMEMENU_SELECT_HPP

#include "MenuItem.hpp"

#include <vector>

namespace MenuElements
{

class Select : public MenuItem
{
public:
    Select(const std::string & name, const std::vector<MenuItem> & selectList);

private:
    std::vector<MenuItem> m_selectList; // should be something else?
};

}


#endif //GAMEMENU_SELECT_HPP
