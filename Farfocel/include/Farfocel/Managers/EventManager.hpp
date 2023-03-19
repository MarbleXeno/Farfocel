#pragma once
#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>

#include "Farfocel/Utils/FunctionCallback.hpp"

namespace fr {
	class EventManager {
	public:
		EventManager();
		EventManager(sf::RenderWindow& renderWindow, sf::Event& evnt);
		~EventManager();

		void AddBinding(const sf::Event::EventType& eventType, const bool& repeat, const std::function<void()> callback);
		const bool IsActive(const sf::Event::EventType& eventType);

		void Update();

		void ClearBinding(const sf::Event::EventType& eventType);
		void ClearAllBindings();
	private:
		sf::RenderWindow* mRenderWindow;
		sf::Event* mEvent;

		std::unordered_map<sf::Event::EventType, std::list<fru::FunctionCallback>> mEventBindings;
		std::vector<sf::Event::EventType> mEventBindingsToRemove;
	};
}