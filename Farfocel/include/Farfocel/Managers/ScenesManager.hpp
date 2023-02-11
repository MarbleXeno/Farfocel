#pragma once
#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Farfocel/Utils/IScene.hpp"

namespace fr {
	class IScene;

	enum class SceneState;
	struct SceneFlags;

	class ScenesManager {
	public:
		ScenesManager();
		~ScenesManager();

		const bool Add(IScene* scene);
		const bool Replace(IScene* scene);
		const uint32_t& SceneCount();

		void Remove(const std::string& id);
		void RemoveAll();
		
		void RemoveAllFocused();
		void RemoveAllUnfocused();

		void FocusAll();
		void UnfocusAll();

		IScene* Get(const std::string& id);

		void Update();
		void Render();
	private:
		std::map<std::string, fr::IScene*> mScenes;
		std::vector<std::string> mScenesToRemove;
	};
}