#include "StateManager.hpp"
using namespace fr;

StateManager::StateManager() 
{

}

StateManager::~StateManager()
{
    
}

void StateManager::replace(IState* state) 
{
    deleteAll();
    addTop(state);    
}

void StateManager::addTop(IState* state) 
{
    m_states.push(state);
}

void StateManager::deleteAll()
{
    while(!m_states.empty())
    {
        deleteTop();
    }
}

void StateManager::deleteTop()
{
    if(!m_states.empty())
    {
        delete getTop();
        m_states.pop();
    }
}

IState* StateManager::getTop()
{
    if(m_states.empty())
    {
        return m_states.top();
    }
    return nullptr;
}

void StateManager::update()
{
    if(!m_states.empty())
        m_states.top()->update();
}

void StateManager::draw()
{
    if(!m_states.empty())
        m_states.top()->draw();
}

