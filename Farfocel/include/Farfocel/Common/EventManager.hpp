#pragma once
#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>

#include "Farfocel/Core/Window.hpp"
#include "Farfocel/Utils/FunctionCallback.hpp"

namespace fr {
	class EventManager {
	public:
		static void Init(fr::Window& window);

		static void AddBinding(const sf::Event::EventType& eventType, const bool& repeat, const std::function<void()>& callback);
        static void AddEventFunction(const std::function<void()>& callback);

		static const bool IsActive(const sf::Event::EventType& eventType);

		static void PoolEvents();

		static void ClearBinding(const sf::Event::EventType& eventType);
		static void ClearAllBindings();
	private:
		static fr::Window* mWindow;

		static std::unordered_map<sf::Event::EventType, std::list<fru::FunctionCallback>> mEventBindings;
		static std::vector<sf::Event::EventType> mEventBindingsToRemove;

        static std::vector<fru::FunctionCallback> mEventFunctions;
	};
}
