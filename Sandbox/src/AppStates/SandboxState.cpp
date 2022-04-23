#include "SandboxState.hpp"

app::SandboxState::SandboxState(fr::StateManager& stateManager, sf::RenderWindow& renderWindow)
	: m_stateManager(&stateManager), m_renderWindow(&renderWindow)
{
}

app::SandboxState::~SandboxState()
{
}

void app::SandboxState::handleEvents()
{
}

void app::SandboxState::handleInput()
{
}

void app::SandboxState::update(const float& deltaTime)
{
}

void app::SandboxState::draw()
{
	m_renderWindow->clear(sf::Color::White);
}
