#include <iostream>

#include "MenuElements/Button.hpp"
#include "MenuElements/MenuItem.hpp"
#include "MenuElements/MenuItemList.hpp"
#include "MenuElements/Label.hpp"
#include "MenuElements/LabelledItem.hpp"
#include "MenuElements/Select.hpp"
#include "MenuElements/Slider.hpp"
#include "MenuElements/Window.hpp"

namespace
{
#define assert_equal(value1, value2) if ((value1) != (value2)) \
    std::cerr << "Assertion failed. File " << __FILE__ \
              << " line " << __LINE__ << " in function " << __FUNCTION__ << std::endl\
              << #value1 << " is equal to " << value1 << " but was expected to be " << value2 << std::endl\


MenuElements::Window initResourcesWindow()
{
    MenuElements::MenuItemList elementList("Resources");
    elementList.appendElementToList(
            MenuElements::LabelledItem("P1 Health",
                                       {MenuElements::Label("P1 Health",
                                                            "P1 Health"),
                                        MenuElements::Slider("Stance",
                                                             {0, 100})}));
    elementList.appendElementToList(
            MenuElements::LabelledItem("P1 Health",
                                       {MenuElements::Label("P2 Health",
                                                            "P2 Health"),
                                        MenuElements::Slider("Stance",
                                                             {0, 100})}));
    elementList.appendElementToList(
            MenuElements::LabelledItem("P1 Health",
                                       {MenuElements::Label("P1 Meter",
                                                            "P1 Meter"),
                                        MenuElements::Slider("Stance",
                                                             {0, 100})}));
    elementList.appendElementToList(
            MenuElements::LabelledItem("P1 Health",
                                       {MenuElements::Label("P2 Meter",
                                                            "P2 Meter"),
                                        MenuElements::Slider("Stance",
                                                             {0, 100})}));
    MenuElements::Window window("Resources", elementList);

    return window;
}

void initTrainingWindow()
{
    MenuElements::MenuItemList elementList("Training");

    MenuElements::Select stanceSelect("Stance", {MenuElements::MenuItem("Stand"),
                                                 MenuElements::MenuItem("Crouch"),
                                                 MenuElements::MenuItem("Jump")});
    elementList.appendElementToList(MenuElements::LabelledItem("Stance",
                                                               {MenuElements::Label(
                                                                       "Stance",
                                                                       "Stance"),
                                                                stanceSelect}));

    elementList.appendElementToList(MenuElements::LabelledItem("Counter",
                                                               {MenuElements::Label(
                                                                       "Counter",
                                                                       "Counter"),
                                                                MenuElements::Select(
                                                                        "Counter",
                                                                        {MenuElements::MenuItem(
                                                                                "Off"),
                                                                         MenuElements::MenuItem(
                                                                                 "On"),
                                                                         MenuElements::MenuItem(
                                                                                 "Random")})}));
    elementList.appendElementToList(MenuElements::Label("Block",
                                                        "Block")); // Off/On/First/Second/Random
    elementList.appendElementToList(::initResourcesWindow());
    elementList.appendElementToList(MenuElements::Button("Command List"));
    elementList.appendElementToList(MenuElements::Button("View Screen"));
    elementList.appendElementToList(MenuElements::Window("Display Options",
                                                         MenuElements::MenuItemList(
                                                                 "")));
    elementList.appendElementToList(
            MenuElements::Button("Return to Character Select"));
    elementList.appendElementToList(MenuElements::Button("Resume")); // Resume

    MenuElements::Window window("Training", elementList);
}

void testinstantiation()
{
    MenuElements::Button button("button");
    MenuElements::MenuItemList elementList("elementList");
    MenuElements::Label label("label", "label");
    MenuElements::LabelledItem labelWithElement("labelWithElement",
                                                {MenuElements::Label("label", "label"),
                                                 MenuElements::MenuItem("element")});
    MenuElements::Select select("select", {});
    MenuElements::Slider slider("slider", {0, 100});
    MenuElements::Slider slider2("slider", {0, 100}, 50);
    MenuElements::Window window("window", MenuElements::MenuItemList("elementList"));
}

void testLambdaOnClick()
{
    int counter = 0;
    auto lambda = [&counter]()
    {
        ++counter;
    };

    MenuElements::Button button("button");
    button.setOnClick(lambda);
    button.update(); // Should be called every frame

    assert_equal(counter, 1);
}

void testMoveCursorNext()
{
    MenuElements::MenuItemList itemList("Test");

    itemList.appendElementToList(MenuElements::Button("button"));
    itemList.appendElementToList(MenuElements::Button("button"));
    itemList.appendElementToList(MenuElements::Button("button"));

    assert_equal(itemList.getCursorIndex(), 0);
    assert_equal(itemList.getItemList()[0].isHovered(), true);
    assert_equal(itemList.getItemList()[1].isHovered(), false);
    assert_equal(itemList.getItemList()[2].isHovered(), false);

    itemList.moveCursor(MenuElements::MenuItemList::Direction::Next);
    assert_equal(itemList.getCursorIndex(), 1);
    assert_equal(itemList.getItemList()[0].isHovered(), false);
    assert_equal(itemList.getItemList()[1].isHovered(), true);
    assert_equal(itemList.getItemList()[2].isHovered(), false);

    itemList.moveCursor(MenuElements::MenuItemList::Direction::Next);
    assert_equal(itemList.getCursorIndex(), 2);
    assert_equal(itemList.getItemList()[0].isHovered(), false);
    assert_equal(itemList.getItemList()[1].isHovered(), false);
    assert_equal(itemList.getItemList()[2].isHovered(), true);

    itemList.moveCursor(MenuElements::MenuItemList::Direction::Next);
    assert_equal(itemList.getItemList()[0].isHovered(), true);
    assert_equal(itemList.getItemList()[1].isHovered(), false);
    assert_equal(itemList.getItemList()[2].isHovered(), false);
    assert_equal(itemList.getCursorIndex(), 0);
}

void testMoveCursorPrevious()
{
    MenuElements::MenuItemList itemList("Test");
    itemList.appendElementToList(MenuElements::Button("button"));
    itemList.appendElementToList(MenuElements::Button("button"));
    itemList.appendElementToList(MenuElements::Button("button"));

    assert_equal(itemList.getCursorIndex(), 0);
    assert_equal(itemList.getItemList()[0].isHovered(), true);
    assert_equal(itemList.getItemList()[1].isHovered(), false);
    assert_equal(itemList.getItemList()[2].isHovered(), false);

    itemList.moveCursor(MenuElements::MenuItemList::Direction::Previous);
    assert_equal(itemList.getCursorIndex(), 2);
    assert_equal(itemList.getItemList()[0].isHovered(), false);
    assert_equal(itemList.getItemList()[1].isHovered(), false);
    assert_equal(itemList.getItemList()[2].isHovered(), true);

    itemList.moveCursor(MenuElements::MenuItemList::Direction::Previous);
    assert_equal(itemList.getCursorIndex(), 1);
    assert_equal(itemList.getItemList()[0].isHovered(), false);
    assert_equal(itemList.getItemList()[1].isHovered(), true);
    assert_equal(itemList.getItemList()[2].isHovered(), false);

    itemList.moveCursor(MenuElements::MenuItemList::Direction::Previous);
    assert_equal(itemList.getItemList()[0].isHovered(), true);
    assert_equal(itemList.getItemList()[1].isHovered(), false);
    assert_equal(itemList.getItemList()[2].isHovered(), false);
    assert_equal(itemList.getCursorIndex(), 0);
}

void testMoveCursorNextAndPrevious()
{
    MenuElements::MenuItemList itemList("Test");
    itemList.appendElementToList(MenuElements::Button("button"));
    itemList.appendElementToList(MenuElements::Button("button"));

    itemList.moveCursor(MenuElements::MenuItemList::Direction::Previous);
    itemList.moveCursor(MenuElements::MenuItemList::Direction::Next);
    itemList.moveCursor(MenuElements::MenuItemList::Direction::Next);
    itemList.moveCursor(MenuElements::MenuItemList::Direction::Previous);
}

void testButtonOutOfScope()
{
    MenuElements::MenuItemList itemList("Test");
    {
        itemList.appendElementToList(MenuElements::Button("button"));
    }

    itemList.getItemList().at(0);
}

}

int main()
{
    // Instantiation Tests
    testinstantiation();
    testButtonOutOfScope();

    // Callback Tests
    testLambdaOnClick();

    // Cursor Tests
    testMoveCursorNext();
    testMoveCursorPrevious();
    testMoveCursorNextAndPrevious();
    //initTrainingWindow();

    return 0;
}