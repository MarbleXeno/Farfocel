/*
    Use it to check for the user's input and bind functions to it.
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <unordered_map>

#include "FunctionBinding.hpp"
namespace fr
{
    class InputManager
    {
    public:
        static void init(sf::RenderWindow& renderWindow);
        static void update();
        static void clearBinding(sf::Keyboard::Key key);
        static void clearBinding(sf::Mouse::Button button);
        static void clearAllBindings();

        static void bindKeyboard(const sf::Keyboard::Key, bool repeat, std::function<void()> function);
        static void bindMouse(const sf::Mouse::Button, bool repeat, std::function<void()> function);

        static bool isKeyboardPressed(const sf::Keyboard::Key key);
        static bool isMousePressed(const sf::Mouse::Button button);
        
        static const sf::Vector2f getMouseRelativePosition();
		static const sf::Vector2f getMouseRelativeCoords();
		static const sf::Vector2f getMousePosition();
		static const sf::Vector2f getMouseCoords();
    private:
    	static sf::RenderWindow* s_renderWindow;
	    static std::unordered_map<sf::Keyboard::Key, fr::FunctionBinding> s_keyboardKeys;
	    static std::unordered_map<sf::Mouse::Button, fr::FunctionBinding> s_mouseButtons;
    };
}