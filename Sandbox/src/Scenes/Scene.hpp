#pragma once
#include "Farfocel/Utils/IScene.hpp"
#include <Farfocel/Core/Renderer.hpp>
#include <Farfocel/Managers/ScenesManager.hpp>
#include <Farfocel/Managers/InputManager.hpp>

#include "SceneTwo.hpp"

namespace sb {
	class Scene : public fr::IScene
	{
	public:
		Scene(const std::string& id, fr::Renderer& renderer, fr::ScenesManager& scenesManager);
		~Scene() override;

		void Start();
		void HandleEvents();
		void HandleInput();
		void Update();
		void Draw();

	private:

		fr::Renderer* mRenderer;

		fr::ScenesManager* mScenesManager;

		fr::InputManager mInputManager;
	};
}


