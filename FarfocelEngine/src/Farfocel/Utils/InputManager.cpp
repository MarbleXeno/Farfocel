#include "InputManager.hpp"

namespace fr
{
	sf::RenderWindow* InputManager::s_renderWindow;
	std::unordered_map<sf::Keyboard::Key, fr_util::FunctionBinding> InputManager::s_keyboardKeys;
	std::unordered_map<sf::Mouse::Button, fr_util::FunctionBinding> InputManager::s_mouseButtons;
}

void fr::InputManager::init(sf::RenderWindow& renderWindow)
{
	s_renderWindow = &renderWindow;
}

void fr::InputManager::bindKeyboard(const sf::Keyboard::Key key, bool repeat, std::function<void()> function)
{
	fr_util::FunctionBinding binding;
    binding.bindFunction(function, repeat);
	s_keyboardKeys[key] = binding;
}

void fr::InputManager::bindMouse(const sf::Mouse::Button button, bool repeat, std::function<void()> function)
{
	fr_util::FunctionBinding binding;
    binding.bindFunction(function, repeat);
	s_mouseButtons[button] = binding;
}

bool isKeyboardPressed(const sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}

bool isMousePressed(const sf::Mouse::Button button)
{
	return sf::Mouse::isButtonPressed(button);
}

const sf::Vector2f fr::InputManager::getMouseRelativePosition()
{
	if (s_renderWindow == NULL)
		return {};
	else
		return sf::Vector2f(sf::Mouse::getPosition(*s_renderWindow));
}

const sf::Vector2f fr::InputManager::getMouseRelativeCoords()
{
	if (s_renderWindow == NULL)
		return {};
	else
		return s_renderWindow->mapPixelToCoords(sf::Mouse::getPosition(*s_renderWindow));
}

const sf::Vector2f fr::InputManager::getMousePosition()
{
	if (s_renderWindow == NULL)
		return {};
	else
		return sf::Vector2f(sf::Mouse::getPosition());
}

const sf::Vector2f fr::InputManager::getMouseCoords()
{
	if (s_renderWindow == NULL)
		return {};
	else
		return s_renderWindow->mapPixelToCoords(sf::Mouse::getPosition());
}

// this prob can be done in an easier and better way :))))))
void fr::InputManager::update()
{
	if (!s_keyboardKeys.empty())
	{
		for (auto& key : s_keyboardKeys)
		{
			if(!sf::Keyboard::isKeyPressed(key.first))
				key.second.changeState(false);

			if(sf::Keyboard::isKeyPressed(key.first))
            {
                if(!key.second.hasToRepeat() && !key.second.hasBeenExecuted())
                    key.second.execFunction();
                else if(key.second.hasToRepeat())
					key.second.execFunction();
            }
		}
	}

	if (!s_mouseButtons.empty())
	{
		for (auto& key : s_mouseButtons)
		{
			if(!sf::Mouse::isButtonPressed(key.first))
				key.second.changeState(false);

			if(sf::Mouse::isButtonPressed(key.first))
            {
                if(!key.second.hasToRepeat() && !key.second.hasBeenExecuted())
                    key.second.execFunction();
                else if(key.second.hasToRepeat())
					key.second.execFunction();
            }
		}
	}
}

void fr::InputManager::clearBinding(sf::Keyboard::Key key)
{
	s_keyboardKeys.erase(key);
}

void fr::InputManager::clearBinding(sf::Mouse::Button button)
{
	s_mouseButtons.erase(button);
}

void fr::InputManager::clearAllBindings()
{
	s_keyboardKeys.clear();
	s_mouseButtons.clear();
}
