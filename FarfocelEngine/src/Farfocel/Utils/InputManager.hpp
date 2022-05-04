/*
    Name:
    InputManager

    Description:
    Manages and stores custom keyboard/mouse input bindings.
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <unordered_map>

#include "FunctionBinder.hpp"
namespace fr
{
    class InputManager
    {
    public:
        /*InputManager();
        InputManager(sf::RenderWindow& renderWindow);
        ~InputManager();*/

        static void init(sf::RenderWindow& renderWindow);

        static void bindKeyboard(const sf::Keyboard::Key, bool repeat, std::function<void()> function);
        static void bindMouse(const sf::Mouse::Button, bool repeat, std::function<void()> function);

        static bool isKeyboardPressed(const sf::Keyboard::Key key);
        static bool isMousePressed(const sf::Mouse::Button button);

        static void updateMouse();
        static void updateKeyboard();

        static const sf::Vector2f getMouseRelativePosition();
        static const sf::Vector2f getMouseRelativeCoords();
        static const sf::Vector2f getMousePosition();
        static const sf::Vector2f getMouseCoords();

        static void clearBinding(sf::Keyboard::Key key);
        static void clearBinding(sf::Mouse::Button button);
        static void clearAllBindings();
        
    private:
        static sf::RenderWindow* s_renderWindow;
        static std::unordered_map<sf::Keyboard::Key, fr_util::FunctionBinder> s_keyboardKeys;
        static std::unordered_map<sf::Mouse::Button, fr_util::FunctionBinder> s_mouseButtons;
    };
}