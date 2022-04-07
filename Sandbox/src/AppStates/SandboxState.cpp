#include "SandboxState.hpp"
using namespace app;

SandboxState::SandboxState(fr::StateManager& stateManager, sf::RenderWindow& renderWindow)
    :   m_stateManager(stateManager), m_renderWindow(renderWindow)
{

    setStateName("SandboxState");
}

SandboxState::~SandboxState()
{
}

void SandboxState::update()
{

}

void SandboxState::draw()
{
    m_renderWindow.clear(sf::Color::Cyan);
}