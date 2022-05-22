#include "InputManager.hpp"

namespace fr
{
	sf::RenderWindow* InputManager::s_renderWindow;
	std::unordered_map<sf::Keyboard::Key, fr_util::FunctionBinder> InputManager::s_keyboardKeys;
	std::unordered_map<sf::Mouse::Button, fr_util::FunctionBinder> InputManager::s_mouseButtons;
}

void fr::InputManager::init(sf::RenderWindow& renderWindow)
{
	s_renderWindow = &renderWindow;
}

void fr::InputManager::bindKeyboard(const sf::Keyboard::Key key, bool repeat, std::function<void()> function)
{
	fr_util::FunctionBinder binding;
    binding.bindFunction(function, repeat);
	s_keyboardKeys[key] = binding;
}

void fr::InputManager::bindMouse(const sf::Mouse::Button button, bool repeat, std::function<void()> function)
{
	fr_util::FunctionBinder binding;
    binding.bindFunction(function, repeat);
	s_mouseButtons[button] = binding;
}

bool fr::InputManager::isKeyboardPressed(const sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}

bool fr::InputManager::isMousePressed(const sf::Mouse::Button button)
{
	return sf::Mouse::isButtonPressed(button);
}

const sf::Vector2f fr::InputManager::getMouseRelativePosition()
{
	if (!s_renderWindow)
	{
		fr::Log::printDebug(fr::LogColor::Red, true, "InputManager: getMouseRelativePosition -> RenderWindow is NULL. Make sure to properly initialize InputManager.");
		return {0.f, 0.f};
	}
	else
		return sf::Vector2f(sf::Mouse::getPosition(*s_renderWindow));
}

const sf::Vector2f fr::InputManager::getMouseRelativeCoords()
{
	if (!s_renderWindow)
	{
		fr::Log::printDebug(fr::LogColor::Red, true, "InputManager: getMouseRelativeCoords -> RenderWindow is NULL. Make sure to properly initialize InputManager.");
		return { 0.f, 0.f };
	}
	else
		return s_renderWindow->mapPixelToCoords(sf::Mouse::getPosition(*s_renderWindow));
}

const sf::Vector2f fr::InputManager::getMousePosition()
{
	if (!s_renderWindow)
	{
		fr::Log::printDebug(fr::LogColor::Red, true, "InputManager: getMousePosition -> RenderWindow is NULL. Make sure to properly initialize InputManager.");
		return { 0.f, 0.f };
	}
	else
		return sf::Vector2f(sf::Mouse::getPosition());
}

const sf::Vector2f fr::InputManager::getMouseCoords()
{
	if (!s_renderWindow)
	{
		fr::Log::printDebug(fr::LogColor::Red, true, "InputManager: getMouseCoords -> RenderWindow is NULL. Make sure to properly initialize InputManager.");
		return { 0.f, 0.f };
	}
	else
		return s_renderWindow->mapPixelToCoords(sf::Mouse::getPosition());
}


void fr::InputManager::updateMouse()
{
	std::unordered_map<sf::Mouse::Button, fr_util::FunctionBinder>::iterator it = s_mouseButtons.begin();

	while (it != s_mouseButtons.end())
	{
		if (it->second.getState() == fr_util::FunctionBinderState::MarkedForRemoval)
		{
			it = s_mouseButtons.erase(it);
		}
		else
		{
			if (!sf::Mouse::isButtonPressed(it->first))
			{
				it->second.changeState(fr_util::FunctionBinderState::NotExecuted);
			}
			else
			{
				if (it->second.hasToRepeat())
					it->second.execFunction();
				else if (!it->second.hasToRepeat() && it->second.getState() == fr_util::FunctionBinderState::NotExecuted)
					it->second.execFunction();
			}

			++it;
		}
	}
}

void fr::InputManager::updateKeyboard()
{
	std::unordered_map<sf::Keyboard::Key, fr_util::FunctionBinder>::iterator it = s_keyboardKeys.begin();

	while (it != s_keyboardKeys.end())
	{
		if (it->second.getState() == fr_util::FunctionBinderState::MarkedForRemoval)
		{
			it = s_keyboardKeys.erase(it);
		}
		else
		{
			if (!sf::Keyboard::isKeyPressed(it->first))
			{
				it->second.changeState(fr_util::FunctionBinderState::NotExecuted);
			}
			else
			{
				if (it->second.hasToRepeat())
					it->second.execFunction();
				else if (!it->second.hasToRepeat() && it->second.getState() == fr_util::FunctionBinderState::NotExecuted)
					it->second.execFunction();
			}

			++it;
		}
	}
}

void fr::InputManager::clearBinding(sf::Keyboard::Key key)
{
	s_keyboardKeys[key].changeState(fr_util::FunctionBinderState::MarkedForRemoval);
}

void fr::InputManager::clearBinding(sf::Mouse::Button button)
{
	s_mouseButtons[button].changeState(fr_util::FunctionBinderState::MarkedForRemoval);
}

void fr::InputManager::clearAllBindings()
{
	for (auto& [key, value] : s_mouseButtons)
	{
		value.changeState(fr_util::FunctionBinderState::MarkedForRemoval);
	}

	for (auto& [key, value] : s_keyboardKeys)
	{
		value.changeState(fr_util::FunctionBinderState::MarkedForRemoval);
	}
}
