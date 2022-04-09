/*
    An Event Manager. Manages and updates app' events. You can also use it to bind functions to specific events.
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "FunctionBinding.hpp"
namespace fr
{
    class EventManager
    {
    public:
        static void init(sf::RenderWindow& renderWindow);
        static void update();
        static sf::Event& getEvent();
        static void addBinding(sf::Event::EventType eventType, bool repeat, std::function<void()> function);
        static void setEvent(sf::Event& event);
        static void clearBiding(sf::Event::EventType eventType);
        static void clearAllBindings();
    private:
        static sf::RenderWindow* s_renderWindow;
        static sf::Event s_event;
        static std::unordered_map<sf::Event::EventType, fr_util::FunctionBinding> s_eventBindings;
    };
}
