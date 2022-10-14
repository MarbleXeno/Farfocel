#include "TestScene.hpp"

sb::TestScene::TestScene(const std::string& id, fr::SFMLUtils* sfml_utils, fr::FRCLUtils* fr_utils)
	: fr::IScene(id), m_sfml(*sfml_utils), m_fr(*fr_utils), m_animation_manager(sfml_utils->render_window)
{
	m_fr.resource_manager.loadTexture("Farfocel_Logo_Spritesheet", "Assets/damian.png");
	m_fr.resource_manager.loadTextureAtlas("Farfocel_Logo", *m_fr.resource_manager.getTexture("Farfocel_Logo_Spritesheet"), { 1, 5 });

	m_animation_manager.add("Farfocel_Logo_Animation", m_farfocel_logo_animated, *m_fr.resource_manager.getTextureAtlas("Farfocel_Logo"));
	m_animation_manager.init("Farfocel_Logo_Animation", 5.f, true, 1, 5);

	m_farfocel_logo_animated.setScale(2.f, 2.f);
	m_farfocel_logo_animated.setOrigin({ m_farfocel_logo_animated.getLocalBounds().width / 2.f, m_farfocel_logo_animated.getLocalBounds().height / 2.f });
	m_farfocel_logo_animated.setPosition(1280 / 2, 720 / 2);
}

sb::TestScene::~TestScene()
{

}

void sb::TestScene::handleEvents()
{

}

void sb::TestScene::handleInput()
{
}

void sb::TestScene::update(const float& delta_time)
{
	m_animation_manager.update(delta_time);
}

void sb::TestScene::draw()
{
	m_sfml.render_window.clear(sf::Color::Black);
	m_animation_manager.draw();
}
