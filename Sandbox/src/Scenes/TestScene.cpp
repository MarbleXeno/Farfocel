#include "TestScene.hpp"

sb::TestScene::TestScene(const std::string& id, fr::SFMLUtils* sfml_utils, fr::FRCLUtils* fr_utils)
	: fr::IScene(id), m_sfml(*sfml_utils), m_fr(*fr_utils)
{

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
}

void sb::TestScene::draw()
{
	m_sfml.render_window.clear(sf::Color::Black);
}
