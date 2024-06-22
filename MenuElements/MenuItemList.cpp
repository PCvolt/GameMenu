//
// Created by PC_volt on 23/09/2023.
//

#include <iostream>
#include "MenuItemList.hpp"

namespace MenuElements
{
MenuItemList::MenuItemList(const std::string & name) : MenuItem(name)
{
}

void MenuItemList::appendElementToList(const MenuElements::MenuItem & element)
{
    m_itemList.push_back(element);

    if (1 == m_itemList.size())
    {
        m_itemList[m_cursorIndex].setHover(true);
    }
}

void MenuItemList::moveCursor(const MenuElements::MenuItemList::Direction direction)
{
    if (!m_itemList.empty())
    {
        m_itemList[m_cursorIndex].setHover(false);
        switch (direction)
        {
            case Direction::Previous:
                m_cursorIndex = (m_cursorIndex - 1 + static_cast<int>(m_itemList.size())) %
                                static_cast<int>(m_itemList.size());
                break;
            case Direction::Next:
                m_cursorIndex = (m_cursorIndex + 1) % static_cast<int>(m_itemList.size());
                break;
        }
        m_itemList[m_cursorIndex].setHover(true);
    }
}

void MenuItemList::update()
{
    MenuItem::update();
    for (auto item: m_itemList)
    {
        item.update();
    }
}

std::vector<MenuItem> MenuItemList::getItemList() const
{
    return m_itemList;
}

int MenuItemList::getCursorIndex() const
{
    return m_cursorIndex;
}

}