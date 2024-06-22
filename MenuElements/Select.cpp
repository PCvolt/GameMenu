//
// Created by PC_volt on 24/09/2023.
//

#include "Select.hpp"

namespace MenuElements
{

Select::Select(const std::string & name, const std::vector<MenuItem> & selectList) : MenuItem(name),
                                                                                     m_selectList(
                                                                                             selectList)
{
}

}