#include "SandboxState.hpp"

app::SandboxState::SandboxState(fr::StateManager& stateManager, sf::RenderWindow& renderWindow)
	: m_stateManager(&stateManager), m_renderWindow(&renderWindow)
{
	m_resourceManager.loadTexture("animated_logo", "res/farfocel_logo_texture_atlas.png");

	m_resourceManager.loadTextureAtlas("texture_atlas", *m_resourceManager.getTexture("animated_logo"), { 1, 5 });

	m_animation = fr_util::Animation(m_animatedLogoSprite, *m_resourceManager.getTextureAtlas("texture_atlas"));
	m_animation.init(30.f, true, 1, 5);
	m_animation.applyTextureToSprite();

	m_animatedLogoSprite.setOrigin(m_animatedLogoSprite.getGlobalBounds().width / 2.f, m_animatedLogoSprite.getGlobalBounds().height / 2.f);
	m_animatedLogoSprite.setPosition({ 640 / 2, 480 / 2 });
	m_animatedLogoSprite.setScale({ 0.4f, 0.4f });
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
	m_animation.play(deltaTime);
}

void app::SandboxState::draw()
{
	m_renderWindow->clear(sf::Color::Black);
	m_renderWindow->draw(m_animatedLogoSprite);
}