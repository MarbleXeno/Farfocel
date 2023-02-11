#include "SceneTwo.hpp"

sb::SceneTwo::SceneTwo(const std::string& id, fr::Renderer& renderer, fr::ScenesManager& scenesManager)
	: IScene(id), mRenderer(&renderer), mInputManager(mRenderer->GetRenderWindow()), mScenesManager(&scenesManager)
{
	
}

sb::SceneTwo::~SceneTwo()
{
}

void sb::SceneTwo::Start()
{
}

void sb::SceneTwo::HandleEvents()
{
}

void sb::SceneTwo::HandleInput()
{
}

void sb::SceneTwo::Update()
{
	
}

void sb::SceneTwo::Draw()
{
	mRenderer->GetRenderWindow().clear(sf::Color::Green);
}
