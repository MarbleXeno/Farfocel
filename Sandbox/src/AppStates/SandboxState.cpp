#include "SandboxState.hpp"
using namespace app;

SandboxState::SandboxState(fr::StateManager& stateManager, sf::RenderWindow& renderWindow)
    :   m_stateManager(stateManager), m_renderWindow(renderWindow)
{

    setStateName("SandboxState");
    
    m_resourceManager.loadTexture("something", "res/something.png");
    m_sprite.setTexture(*m_resourceManager.getTexture("something"));
}

SandboxState::~SandboxState()
{
}

void SandboxState::update()
{

}

void SandboxState::draw()
{
    m_renderWindow.draw(m_sprite);
}