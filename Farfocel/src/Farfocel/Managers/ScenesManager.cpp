#include "Farfocel/Managers/ScenesManager.hpp"

fr::ScenesManager::ScenesManager()
{
}

fr::ScenesManager::~ScenesManager()
{
	RemoveAll();
}

const bool fr::ScenesManager::Add(IScene* scene)
{
	mScenes[scene->GetID()] = scene;
	scene->Start();
	return true;
}

const bool fr::ScenesManager::Replace(IScene* scene)
{
	UnfocusAll();		// Ain't removing anything.
	Add(scene);
	return true;
}

const uint32_t& fr::ScenesManager::SceneCount()
{
	return mScenes.size();
}

void fr::ScenesManager::Remove(const std::string& id)
{
	// Implement something to stop updating since it might break the updating loop. IDK, have to test it. Maybe it wont break it

	mScenesToRemove.push_back(id);
}

void fr::ScenesManager::RemoveAll()
{
	for (auto& [id, scene] : mScenes) {
		mScenesToRemove.push_back(id);
	}
}

void fr::ScenesManager::RemoveAllFocused()
{
	for (auto& [id, scene] : mScenes) {
		if (scene->GetState() == SceneState::Focused) {
			mScenesToRemove.push_back(id);
		}
	}
}

void fr::ScenesManager::RemoveAllUnfocused()
{
	for (auto& [id, scene] : mScenes) {
		if (scene->GetState() == SceneState::Unfocused) {
			mScenesToRemove.push_back(id);
		}
	}
}

void fr::ScenesManager::FocusAll()
{
	for (auto& [id, scene] : mScenes) {
		if (scene->GetState() == SceneState::Unfocused) {
			scene->SetState(SceneState::Focused);
		}
	}
}

void fr::ScenesManager::UnfocusAll()
{
	for (auto& [id, scene] : mScenes) {
		if (scene->GetState() == SceneState::Focused) {
			scene->SetState(SceneState::Unfocused);
		}
	}
}

fr::IScene* fr::ScenesManager::Get(const std::string& id)
{
	for (auto& [sceneID, scene] : mScenes) {
		if (sceneID == id) {
			return scene;
		}
	}

	return nullptr;
}

void fr::ScenesManager::Update()
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

void fr::ScenesManager::Render()
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
