cmake_minimum_required(VERSION 3.21)
project(GameMenu VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

add_library(
  MenuElements
  MenuElements/MenuItem.cpp
  MenuElements/MenuItem.hpp
  MenuElements/Position.hpp
  MenuElements/Size.hpp
  MenuElements/Label.cpp
  MenuElements/Label.hpp
  MenuElements/LabelledItem.cpp
  MenuElements/LabelledItem.hpp
  MenuElements/MenuItemList.cpp
  MenuElements/MenuItemList.hpp
  MenuElements/Window.cpp
  MenuElements/Window.hpp
  MenuElements/Button.cpp
  MenuElements/Button.hpp
  MenuElements/Slider.cpp
  MenuElements/Slider.hpp
  MenuElements/Select.cpp
  MenuElements/Select.hpp)

add_executable(GameMenu main.cpp)

target_link_libraries(GameMenu PRIVATE MenuElements)
target_include_directories(GameMenu PRIVATE MenuElements)
