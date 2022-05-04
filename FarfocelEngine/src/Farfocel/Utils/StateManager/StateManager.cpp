#include "StateManager.hpp"

fr::StateManager::StateManager()
{

}

fr::StateManager::~StateManager()
{
	popAll();
}

void fr::StateManager::add(std::unique_ptr<IState> state)
{
	m_states.push(std::move(state));
}

void fr::StateManager::replace(std::unique_ptr<IState> state)
{
	pop();
	m_states.push(std::move(state));
}

void fr::StateManager::pop()
{
	if (m_states.empty())
	{
		fr::Log::printDebug(fr::LogColor::White, true, "StateManager: pop -> State stack is already empty, no need to pop anything.");
		return;
	}
	
	m_states.pop();
}

void fr::StateManager::popAll()
{
	while (!m_states.empty())
	{
		pop();
	}
}

void fr::StateManager::stateHandleEvents()
{
	if(!m_states.empty())
		m_states.top()->handleEvents();
}

void fr::StateManager::stateHandleInput()
{
	if (!m_states.empty())
		m_states.top()->handleEvents();
}

void fr::StateManager::stateUpdate(const float& deltaTime)
{
	if (!m_states.empty())
		m_states.top()->update(deltaTime);
}

void fr::StateManager::stateDraw()
{
	if (!m_states.empty())
		m_states.top()->draw();
}
