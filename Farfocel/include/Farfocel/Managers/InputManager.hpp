#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>
#include <iostream>
#include <list>

#include "Farfocel/Utils/FunctionCallback.hpp"

namespace fr
{
	class InputManager {
	public:
		InputManager();
		InputManager(sf::RenderWindow& renderWindow);
		~InputManager();

		void Bind(const sf::Keyboard::Key& key, const bool& repeat, const std::function<void()> callback);
		void Bind(const sf::Mouse::Button button, const bool& repeat, const std::function<void()> callback);

		const bool IsPressed(const sf::Keyboard::Key& key);
		const bool IsPressed(const sf::Mouse::Button& button);

		const sf::Vector2f GetMouseRelativePosition();
		const sf::Vector2f GetMouseRelativeCoords();
		const sf::Vector2f GetMousePosition();
		const sf::Vector2f GetMouseCoords();

		void UpdateMouse();
		void UpdateKeyboard();

		void ClearBinding(sf::Keyboard::Key key);
		void ClearBinding(sf::Mouse::Button	button);
		void ClearAllBindings();

	private:
		sf::RenderWindow* mRenderWindow;

		std::unordered_map<sf::Keyboard::Key, std::list<fru::FunctionCallback>> mKeyboardBinds;
		std::unordered_map<sf::Mouse::Button, std::list<fru::FunctionCallback>> mMouseBinds;

		std::vector<sf::Keyboard::Key> mKeyboardBindsToRemove;
		std::vector<sf::Mouse::Button> mMouseBindsToRemove;

	};
}