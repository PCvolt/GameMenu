//
// Created by PC_volt on 23/09/2023.
//

#include "Window.hpp"

namespace
{
MenuElements::Window *topWindow = nullptr;
}

namespace MenuElements
{
Window::Window(const std::string & name, const MenuItemList & elementList) : MenuItem(name),
                                                                             m_elementList(
                                                                                     elementList),
                                                                             m_isOnTop(true)
{
    topWindow = this;
}

Window::~Window()
{
    topWindow = m_parentWindow;
}

void Window::assignElementList(const MenuItemList & elementList)
{
    m_elementList = elementList;
}

}