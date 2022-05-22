/*
    Name:
    EventManager

    Description:
    Similar to InputManager but handles app events. Don't use it for managing the inputs.
*/

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
        /*EventManager();
        EventManager(sf::RenderWindow& renderWindow, sf::Event& evnt);
        ~EventManager();*/

        static void init(sf::RenderWindow& renderWindow, sf::Event& evnt);

        static const sf::Event* getEvent();

        static void updateEvents();
        
        static void addBinding(sf::Event::EventType eventType, bool repeat, std::function<void()> function);
        
        static void clearBinding(sf::Event::EventType eventType);
        static void clearAllBindings();
    private:
        static bool s_stopperinyo;

        static sf::RenderWindow* s_renderWindow;
        static sf::Event* s_event;
        static std::unordered_map<sf::Event::EventType, fr_util::FunctionBinder> s_eventBindings;
    };
}