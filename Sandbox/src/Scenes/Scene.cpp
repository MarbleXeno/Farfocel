#include "Scene.hpp"

sb::Scene::Scene(const std::string& id, fr::Renderer& renderer, fr::ScenesManager& scenesManager)
	: IScene(id), mRenderer(&renderer), mScenesManager(&scenesManager), mInputManager(renderer.GetRenderWindow())
{
	
	

}

sb::Scene::~Scene()
{

}

void sb::Scene::Start()
{
	mInputManager.Bind(sf::Mouse::Left, true, [=]() {mScenesManager->RemoveAll(); });
	mInputManager.Bind(sf::Mouse::Right, true, [=]() {mScenesManager->Add(new SceneTwo("sceneTWOSS", *mRenderer, *mScenesManager)); });
}

void sb::Scene::HandleEvents()
{

}

void sb::Scene::HandleInput()
{
	
}

void sb::Scene::Update()
{
	mInputManager.UpdateMouse();
}

void sb::Scene::Draw()
{
	mRenderer->GetRenderWindow().clear(sf::Color::Yellow);
}
