#include "Function/EventManager.hpp"


fr::EventManager::EventManager()
    :   m_render_window(nullptr), m_event(nullptr)
{

}

fr::EventManager::EventManager(sf::RenderWindow& render_window, sf::Event& evnt)
{
    m_render_window = &render_window;
    m_event = &evnt;
}

fr::EventManager::~EventManager()
{
    clearAllBindings();
}

void fr::EventManager::updateEvents()
{
    if (!m_render_window || !m_event)
    {
        return;
    }

    auto it = m_event_bindings.begin();
    auto next_it = it;

    while (it != m_event_bindings.end() && m_render_window->pollEvent(*m_event))
    {
        next_it++;

        if (it->second.getState() == fru::FunctionBinderState::MarkedForRemoval)
        {
            m_event_bindings.erase(it);
        }
        else
        {
            if (it->first == m_event->type)
            {
                if (!it->second.hasToRepeat() && it->second.getState() == fru::FunctionBinderState::Executed)
                {
                    it->second.changeState(fru::FunctionBinderState::MarkedForRemoval);
                }
                else
                {
                    it->second.execFunction();
                }
            }
        }

        it = next_it;
    }
}



const sf::Event& fr::EventManager::getEvent()
{
    if (m_event)
    {
        return *m_event;
    }

    return sf::Event();

}

void fr::EventManager::addBinding(sf::Event::EventType event_type, bool repeat, std::function<void()> function)
{
    fru::FunctionBinder callback;
    callback.bindFunction(function, repeat);
    m_event_bindings[event_type] = callback;
}

void fr::EventManager::clearBinding(sf::Event::EventType event_type)
{
    m_event_bindings[event_type].changeState(fru::FunctionBinderState::MarkedForRemoval);
}

void fr::EventManager::clearAllBindings()
{
    for (auto& [key, value] : m_event_bindings)
    {
        value.changeState(fru::FunctionBinderState::MarkedForRemoval);
    }
}