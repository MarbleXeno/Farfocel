#include "Farfocel/Common/EventManager.hpp"

fr::Window* fr::EventManager::mWindow;

std::unordered_map<sf::Event::EventType, std::list<fru::FunctionCallback>> fr::EventManager::mEventBindings;
std::vector<sf::Event::EventType> fr::EventManager::mEventBindingsToRemove;
std::vector<fru::FunctionCallback> fr::EventManager::mEventFunctions;

void fr::EventManager::Init(fr::Window& window)
{
	mWindow = &window;
}

void fr::EventManager::AddBinding(const sf::Event::EventType& eventType, const bool& repeat, const std::function<void()>& callback) {
	mEventBindings[eventType].push_back(fru::FunctionCallback(repeat, callback));
}

void fr::EventManager::AddEventFunction(const std::function<void()>& callback) {
    mEventFunctions.push_back(fru::FunctionCallback(true, callback));
}

const bool fr::EventManager::IsActive(const sf::Event::EventType& eventType) {
	if (mWindow->GetEvent().type == eventType) { return true; }
	return false;
}

void fr::EventManager::PoolEvents() {
	if (!mWindow) { return; }
	while (mWindow->PoolEvents()) {
		for (auto key : mEventBindingsToRemove) {
			mEventBindings.erase(key);
		}
		mEventBindingsToRemove.clear();

        for(auto& callback : mEventFunctions){
            callback.Execute();
        }

		for (auto& [key, bindings] : mEventBindings) {
            for (auto binding: bindings) {
                if (key != mWindow->GetEvent().type) { binding.SetState(fru::FunctionCallbackState::MarkedForExec); }
                else if (binding.GetRepeat()) { binding.Execute(); }
                else if (!binding.GetRepeat() &&
                         binding.GetState() == fru::FunctionCallbackState::MarkedForExec) { binding.Execute(); }
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
