#include "Function/InputManager.hpp"

fr::InputManager::InputManager()
	: m_render_window(nullptr)
{
}

fr::InputManager::InputManager(sf::RenderWindow& render_window)
	: m_render_window(&render_window)
{

}

fr::InputManager::~InputManager()
{
	clearAllBindings();
}

void fr::InputManager::bind(const sf::Keyboard::Key key, bool repeat, std::function<void()> callback)
{
	fru::FunctionBinder binding;
	binding.bindFunction(callback, repeat);
	m_keyboad_keys[key] = binding;
}

void fr::InputManager::bind(const sf::Mouse::Button button, bool repeat, std::function<void()> callback)
{
	fru::FunctionBinder binding;
	binding.bindFunction(callback, repeat);
	m_mouse_buttons[button] = binding;
}

const bool fr::InputManager::isPressed(const sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}

const bool fr::InputManager::isPressed(const sf::Mouse::Button button)
{
	return sf::Mouse::isButtonPressed(button);
}

void fr::InputManager::updateMouse()
{
	std::unordered_map<sf::Mouse::Button, fru::FunctionBinder>::iterator it = m_mouse_buttons.begin();
	auto next_it = it;

	while (it != m_mouse_buttons.end())
	{
		next_it++;

		if (it->second.getState() == fru::FunctionBinderState::MarkedForRemoval)
		{
			m_mouse_buttons.erase(it);
		}
		else
		{
			if (!sf::Mouse::isButtonPressed(it->first))
			{
				it->second.changeState(fru::FunctionBinderState::NotExecuted);
			}
			else
			{
				if (it->second.hasToRepeat())
					it->second.execFunction();

				if (!it->second.hasToRepeat() && it->second.getState() == fru::FunctionBinderState::NotExecuted)
					it->second.execFunction();
			}
		}

		it = next_it;
	}
}

void fr::InputManager::updateKeyboard()
{
	std::unordered_map<sf::Keyboard::Key, fru::FunctionBinder>::iterator it = m_keyboad_keys.begin();
	auto next_it = it;

	while (it != m_keyboad_keys.end())
	{
		next_it++;

		if (it->second.getState() == fru::FunctionBinderState::MarkedForRemoval)
		{
			m_keyboad_keys.erase(it);
		}
		else
		{

			if (!sf::Keyboard::isKeyPressed(it->first))
			{
				it->second.changeState(fru::FunctionBinderState::NotExecuted);
			}
			else
			{
				if (it->second.hasToRepeat())
					it->second.execFunction();

				if (!it->second.hasToRepeat() && it->second.getState() == fru::FunctionBinderState::NotExecuted)
					it->second.execFunction();
			}
		}

		it = next_it;
	}
}

const sf::Vector2f fr::InputManager::getMouseRelativePosition()
{
	if (!m_render_window)
		return sf::Vector2f();
	else
		return sf::Vector2f(sf::Mouse::getPosition(*m_render_window));
}

const sf::Vector2f fr::InputManager::getMouseRelativeCoords()
{
	if (!m_render_window)
		return {0.f, 0.f};
	else
		return m_render_window->mapPixelToCoords(sf::Mouse::getPosition(*m_render_window));
}

const sf::Vector2f fr::InputManager::getMousePosition()
{
	if (!m_render_window)
		return sf::Vector2f();
	else
		return sf::Vector2f(sf::Mouse::getPosition());
}

const sf::Vector2f fr::InputManager::getMouseCoords()
{
	if (!m_render_window)
		return sf::Vector2f();
	else
		return m_render_window->mapPixelToCoords(sf::Mouse::getPosition());
}

void fr::InputManager::clearBinding(sf::Keyboard::Key key)
{
	m_keyboad_keys[key].changeState(fru::FunctionBinderState::MarkedForRemoval);
}

void fr::InputManager::clearBinding(sf::Mouse::Button button)
{
	m_mouse_buttons[button].changeState(fru::FunctionBinderState::MarkedForRemoval);
}

void fr::InputManager::clearAllBindings()
{
	for (auto& [key, value] : m_mouse_buttons)
	{
		value.changeState(fru::FunctionBinderState::MarkedForRemoval);
	}

	for (auto& [key, value] : m_keyboad_keys)
	{
		value.changeState(fru::FunctionBinderState::MarkedForRemoval);
	}
}
