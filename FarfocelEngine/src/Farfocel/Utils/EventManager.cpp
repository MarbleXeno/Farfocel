#include "EventManager.hpp"

namespace fr
{
    sf::RenderWindow* EventManager::s_renderWindow;
    sf::Event EventManager::s_event;
    std::unordered_map<sf::Event::EventType, fr_util::FunctionBinding> EventManager::s_eventBindings;
}

void fr::EventManager::init(sf::RenderWindow& renderWindow) 
{
    s_renderWindow = &renderWindow;

    s_event = sf::Event();
}

void fr::EventManager::update()
{
    while (s_renderWindow->pollEvent(s_event))
    {
        if (s_event.type == sf::Event::Closed)
        {
            clearAllBindings();
            s_renderWindow->close();
            break;
        }
        else
        {
            for (auto& it : s_eventBindings)
            {
                if (it.first == s_event.type)
                {
                    it.second.execFunction();
                    if (!it.second.hasToRepeat() && it.second.hasBeenExecuted())
                        s_eventBindings.erase(it.first);
                }
            }
        }
    }
}

sf::Event& fr::EventManager::getEvent()
{
    return s_event;
}

void fr::EventManager::addBinding(sf::Event::EventType eventType, bool repeat, std::function<void()> function)
{
    fr_util::FunctionBinding callback;
    callback.bindFunction(function, repeat);
    s_eventBindings[eventType] = callback;
}

void fr::EventManager::setEvent(sf::Event& event)
{
    s_event = event;
}

void fr::EventManager::clearBiding(sf::Event::EventType eventType)
{
    s_eventBindings.erase(eventType);
}

void fr::EventManager::clearAllBindings()
{
    s_eventBindings.clear();
}