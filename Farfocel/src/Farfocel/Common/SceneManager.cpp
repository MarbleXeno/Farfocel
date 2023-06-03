#include "Farfocel/Common/SceneManager.hpp"

fr::SceneManager::SceneManager()
{
}

fr::SceneManager::~SceneManager()
{
	RemoveAll();
}

const bool fr::SceneManager::Add(IScene* scene)
{
	mScenes[scene->GetID()] = scene;
	scene->Start();
	return true;
}

const bool fr::SceneManager::Replace(IScene* scene)
{
	UnfocusAll();		// Ain't removing anything.
	Add(scene);
	return true;
}

const uint32_t fr::SceneManager::SceneCount()
{
	return mScenes.size();
}

void fr::SceneManager::Remove(const std::string& id)
{
	// Implement something to stop updating since it might break the updating loop. IDK, have to test it. Maybe it wont break it

	mScenesToRemove.push_back(id);
}

void fr::SceneManager::RemoveAll()
{
	for (auto& [id, scene] : mScenes) {
		mScenesToRemove.push_back(id);
	}
}

void fr::SceneManager::RemoveAllFocused()
{
	for (auto& [id, scene] : mScenes) {
		if (scene->GetState() == SceneState::Focused) {
			mScenesToRemove.push_back(id);
		}
	}
}

void fr::SceneManager::RemoveAllUnfocused()
{
	for (auto& [id, scene] : mScenes) {
		if (scene->GetState() == SceneState::Unfocused) {
			mScenesToRemove.push_back(id);
		}
	}
}

void fr::SceneManager::FocusAll()
{
	for (auto& [id, scene] : mScenes) {
		if (scene->GetState() == SceneState::Unfocused) {
			scene->SetState(SceneState::Focused);
		}
	}
}

void fr::SceneManager::UnfocusAll()
{
	for (auto& [id, scene] : mScenes) {
		if (scene->GetState() == SceneState::Focused) {
			scene->SetState(SceneState::Unfocused);
		}
	}
}

fr::IScene* fr::SceneManager::Get(const std::string& id)
{
	for (auto& [sceneID, scene] : mScenes) {
		if (sceneID == id) {
			return scene;
		}
	}

	return nullptr;
}

void fr::SceneManager::Update()
{
	for (auto id : mScenesToRemove) {
		mScenes.erase(id);
	}
	mScenesToRemove.clear();

	for (auto& [id, scene] : mScenes) {
		if (scene->GetState() == SceneState::Focused) {
			if (scene->GetFlags().canHandleEvents) { scene->HandleEvents(); }
			if (scene->GetFlags().canHandleInput) { scene->HandleInput(); }
			if (scene->GetFlags().canUpdate) { scene->Update(); }
		}
	}

}

void fr::SceneManager::Render()
{
	for (auto id : mScenesToRemove) {
		mScenes.erase(id);
	}
	mScenesToRemove.clear();

	for (auto& [id, scene] : mScenes) {
		if (scene->GetState() == SceneState::Focused && scene->GetFlags().canDraw) {
			scene->Draw();
		}
	}

}
