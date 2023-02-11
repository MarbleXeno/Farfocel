#include "Farfocel/Managers/InputManager.hpp"

fr::InputManager::InputManager()
	: mRenderWindow()
{
}

fr::InputManager::InputManager(sf::RenderWindow& renderWindow)
	: mRenderWindow(&renderWindow)
{
}

fr::InputManager::~InputManager()
{
	ClearAllBindings();
}

void fr::InputManager::Bind(const sf::Keyboard::Key& key, const bool& repeat, const std::function<void()> callback)
{
	mKeyboardBinds[key].push_back(fru::FunctionCallback(repeat, callback));
}

void fr::InputManager::Bind(const sf::Mouse::Button button, const bool& repeat, const std::function<void()> callback)
{
	mMouseBinds[button].push_back(fru::FunctionCallback(repeat, callback));
}

const bool fr::InputManager::IsPressed(const sf::Keyboard::Key& key)
{
	return sf::Keyboard::isKeyPressed(key);
}

const bool fr::InputManager::IsPressed(const sf::Mouse::Button& button)
{
	return sf::Mouse::isButtonPressed(button);
}

const sf::Vector2f fr::InputManager::GetMouseRelativePosition()
{
	if (!mRenderWindow) { return sf::Vector2f(); }
	return sf::Vector2f(sf::Mouse::getPosition(*mRenderWindow));
}

const sf::Vector2f fr::InputManager::GetMouseRelativeCoords()
{
	if (!mRenderWindow) { return sf::Vector2f(); }
	return mRenderWindow->mapPixelToCoords(sf::Mouse::getPosition(*mRenderWindow));
}

const sf::Vector2f fr::InputManager::GetMousePosition()
{
	if (!mRenderWindow) { return sf::Vector2f(); }
	return sf::Vector2f(sf::Mouse::getPosition());
}

const sf::Vector2f fr::InputManager::GetMouseCoords()
{
	if (!mRenderWindow) { return sf::Vector2f(); }
	return mRenderWindow->mapPixelToCoords(sf::Mouse::getPosition());
}

void fr::InputManager::UpdateKeyboard()
{
	if (!mRenderWindow) { return; }

	for (auto key : mKeyboardBindsToRemove) { mKeyboardBinds.erase(key); }
	mKeyboardBindsToRemove.clear();

	for (auto& [key, bindings] : mKeyboardBinds) {
		for (auto& binding : bindings) {
			if (!sf::Keyboard::isKeyPressed(key)) { binding.SetState(fru::FunctionCallbackState::MarkedForExec); }
			else if (binding.Repeat()) { binding.Execute(); }
			else if (!binding.Repeat() && binding.GetState() == fru::FunctionCallbackState::MarkedForExec) { binding.Execute(); }
		}
	}
}

void fr::InputManager::UpdateMouse()
{
	if (!mRenderWindow) { return; }

	for (auto button : mMouseBindsToRemove) { mMouseBinds.erase(button); }
	mMouseBindsToRemove.clear();

	for (auto& [button, bindings] : mMouseBinds) {
		for (auto& binding : bindings) {
			if (!sf::Mouse::isButtonPressed(button)) { binding.SetState(fru::FunctionCallbackState::MarkedForExec); }
			else if (binding.Repeat()) { binding.Execute(); }
			else if (binding.GetState() == fru::FunctionCallbackState::MarkedForExec) { binding.Execute(); }
		}
	}

	
}

void fr::InputManager::ClearBinding(sf::Keyboard::Key key)
{
	mKeyboardBindsToRemove.push_back(key);
}

void fr::InputManager::ClearBinding(sf::Mouse::Button button)
{
	mMouseBindsToRemove.push_back(button);
}

void fr::InputManager::ClearAllBindings()
{
	for (auto& [key, bindings] : mKeyboardBinds) {
		mKeyboardBindsToRemove.push_back(key);
	}

	for (auto& [button, bindings] : mMouseBinds) {
		mMouseBindsToRemove.push_back(button);
	}
}

