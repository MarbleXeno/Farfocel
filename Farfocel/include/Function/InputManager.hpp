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
		InputManager();
		InputManager(sf::RenderWindow& render_window);
		~InputManager();

		void bind(const sf::Keyboard::Key key, bool repeat, std::function<void()> callback);
		void bind(const sf::Mouse::Button button, bool repeat, std::function<void()> callback);

		const bool isPressed(const sf::Keyboard::Key key);
		const bool isPressed(const sf::Mouse::Button button);

		void updateMouse();
		void updateKeyboard();

		const sf::Vector2f getMouseRelativePosition();
		const sf::Vector2f getMouseRelativeCoords();
		const sf::Vector2f getMousePosition();
		const sf::Vector2f getMouseCoords();

		void clearBinding(sf::Keyboard::Key key);
		void clearBinding(sf::Mouse::Button	button);
		void clearAllBindings();
	private:
		sf::RenderWindow* m_render_window;
		std::unordered_map<sf::Keyboard::Key, fru::FunctionBinder> m_keyboad_keys;
		std::unordered_map<sf::Mouse::Button, fru::FunctionBinder> m_mouse_buttons;
	};
}
