#include "SandboxState.hpp"

app::SandboxState::SandboxState(fr::StateManager& stateManager, sf::RenderWindow& renderWindow)
	: m_stateManager(&stateManager), m_renderWindow(&renderWindow), m_animationManager(*m_renderWindow)
{
	m_resourceManager.loadTexture("animated_logo", "res/farfocel_logo_texture_atlas.png");

	m_resourceManager.loadTextureAtlas("texture_atlas", *m_resourceManager.getTexture("animated_logo"), { 1, 5 });

	m_animationManager.add("animated_farfocel_logo", m_sprite, *m_resourceManager.getTextureAtlas("texture_atlas"));
	m_animationManager.init("animated_farfocel_logo", 5.f, true, 1, 5);

	fr::InputManager::bindKeyboard(sf::Keyboard::D, false, [=]() {m_animationManager.changeAnimationState("animated_farfocel_logo", fr::AnimationState::Paused); });
	fr::InputManager::bindKeyboard(sf::Keyboard::A, false, [=]() {m_animationManager.changeAnimationState("animated_farfocel_logo", fr::AnimationState::Playing); });


	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f, m_sprite.getGlobalBounds().height / 2.f);
	m_sprite.setScale({ 0.5f, 0.5f });
	m_sprite.setPosition({ 640.f / 2.f, 480.f / 2.f });
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
	m_animationManager.update(deltaTime);
}

void app::SandboxState::draw()
{
	m_renderWindow->clear(sf::Color::Black);
	m_animationManager.draw();
}