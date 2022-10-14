#pragma once
#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include <map>

#include "FunctionBinder.hpp"
namespace fr
{
    class EventManager
    {
    public:
        EventManager();
        EventManager(sf::RenderWindow& render_window, sf::Event& evnt);
        ~EventManager();

        const sf::Event& getEvent();

        void updateEvents();

        void addBinding(sf::Event::EventType event_type, bool repeat, std::function<void()> function);

        void clearBinding(sf::Event::EventType event_type);
        void clearAllBindings();
    private:
        sf::RenderWindow* m_render_window;
        sf::Event* m_event;
        std::unordered_map<sf::Event::EventType, fru::FunctionBinder> m_event_bindings;
    };
}