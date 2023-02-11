#include "Farfocel/Managers/EventManager.hpp"

fr::EventManager::EventManager()
	: mRenderWindow(nullptr), mEvent(nullptr) {
}

fr::EventManager::EventManager(sf::RenderWindow& renderWindow, sf::Event& evnt)
	: mRenderWindow(&renderWindow), mEvent(&evnt){
}

fr::EventManager::~EventManager() {
	ClearAllBindings();
}

void fr::EventManager::AddBinding(const sf::Event::EventType& eventType, const bool& repeat, const std::function<void()> callback) {
	mEventBindings[eventType].push_back(fru::FunctionCallback(repeat, callback));
}

const bool fr::EventManager::IsActive(const sf::Event::EventType& eventType) {
	if (mEvent->type == eventType) { return true; }
	return false;
}

void fr::EventManager::Update() {
	if (!mRenderWindow || !mEvent) { return; }
	
	while (mRenderWindow->pollEvent(*mEvent)) {
		ImGui::SFML::ProcessEvent(*mRenderWindow, *mEvent);

		for (auto key : mEventBindingsToRemove) {
			mEventBindings.erase(key);
		}
		mEventBindingsToRemove.clear();

		for (auto& [key, bindings] : mEventBindings) {
			for (auto binding : bindings) {
				if (key != mEvent->type) { binding.SetState(fru::FunctionCallbackState::MarkedForExec); }
				else if (binding.Repeat()) { binding.Execute(); }
				else if (!binding.Repeat() && binding.GetState() == fru::FunctionCallbackState::MarkedForExec) { binding.Execute(); }
			}
		}
	
	}
}

void fr::EventManager::ClearBinding(const sf::Event::EventType& eventType)
{
	mEventBindingsToRemove.push_back(eventType);
}

void fr::EventManager::ClearAllBindings()
{
	for (auto& [key, bindings] : mEventBindings) {
		mEventBindingsToRemove.push_back(key);
	}
}
