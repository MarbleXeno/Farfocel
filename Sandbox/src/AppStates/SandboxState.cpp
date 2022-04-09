#include "SandboxState.hpp"
using namespace app;

SandboxState::SandboxState(fr::StateManager& stateManager, sf::RenderWindow& renderWindow)
    :   m_stateManager(stateManager), m_renderWindow(renderWindow)
{

    setStateName("SandboxState");
    
    // just checking if we can use the same texture more than once
    m_resourceManager.loadTexture("something", "res/something.png");
    m_sprite.setTexture(*m_resourceManager.getTexture("something"));

    m_secondSprite.setTexture(*m_resourceManager.getTexture("something"));
    m_secondSprite.setPosition({ 320,280 });
    m_secondSprite.setScale({ 0.5,0.2 });

    fr::InputManager::bindMouse(sf::Mouse::Left, true, [=]() {
        m_stateManager.deleteAll();
    });
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
    m_renderWindow.draw(m_sprite);
    m_renderWindow.draw(m_secondSprite);
}