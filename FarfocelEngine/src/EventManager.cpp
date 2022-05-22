#include "EventManager.hpp"

namespace fr
{
    bool EventManager::s_stopperinyo;
    sf::RenderWindow* EventManager::s_renderWindow;
    sf::Event* EventManager::s_event;
    std::unordered_map<sf::Event::EventType, fr_util::FunctionBinder> EventManager::s_eventBindings;
}

void fr::EventManager::init(sf::RenderWindow& renderWindow, sf::Event& evnt)
{
    s_stopperinyo = false;
    s_renderWindow = &renderWindow;
    s_event = &evnt;
}

void fr::EventManager::updateEvents()
{
    if (!s_renderWindow || !s_event)
    {
        if (!s_stopperinyo)
        {
            fr::Log::printDebug(fr::LogColor::Red, true, "EventManager: updateEvents -> EventManager is not properly initialized.");
            s_stopperinyo = true;
        }
        return;
    }

    while (s_renderWindow->pollEvent(*s_event))
    {
        std::unordered_map<sf::Event::EventType, fr_util::FunctionBinder>::iterator it = s_eventBindings.begin();

        while (it != s_eventBindings.end())
        {
            if (it->second.getState() == fr_util::FunctionBinderState::MarkedForRemoval)
            {
                it = s_eventBindings.erase(it);
            }
            else
            {
                if (it->first == s_event->type)
                {
                    if (!it->second.hasToRepeat() && it->second.getState() == fr_util::FunctionBinderState::Executed)
                    {
                        it->second.changeState(fr_util::FunctionBinderState::MarkedForRemoval);
                    }
                    else
                    {
                        it->second.execFunction();
                    }
                }
                ++it;
            }
        }
    }
}



const sf::Event* fr::EventManager::getEvent()
{
    if (s_event)
    {
        return s_event;
    }

    fr::Log::printDebug(fr::LogColor::Red, true, "EventManager: getEvent -> EventManager is not properly initialized. Returning nullptr.");
    return nullptr;

}

void fr::EventManager::addBinding(sf::Event::EventType eventType, bool repeat, std::function<void()> function)
{
    fr_util::FunctionBinder callback;
    callback.bindFunction(function, repeat);
    s_eventBindings[eventType] = callback;
}

void fr::EventManager::clearBinding(sf::Event::EventType eventType)
{
    s_eventBindings[eventType].changeState(fr_util::FunctionBinderState::MarkedForRemoval);
}

void fr::EventManager::clearAllBindings()
{
    for (auto& [key, value] : s_eventBindings)
    {
        value.changeState(fr_util::FunctionBinderState::MarkedForRemoval);
    }
}