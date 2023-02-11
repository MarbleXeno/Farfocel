#pragma once
#include "Farfocel/Utils/IScene.hpp"
#include "Farfocel/Core/Renderer.hpp"
#include "Farfocel/Managers/InputManager.hpp"
#include "Farfocel/Managers/ScenesManager.hpp"

namespace sb {
	class SceneTwo : public fr::IScene
	{
	public:
		SceneTwo(const std::string& id, fr::Renderer& renderer, fr::ScenesManager& scenesManager);
		~SceneTwo() override;

		void Start();
		void HandleEvents();
		void HandleInput();
		void Update();
		void Draw();

	private:

		fr::Renderer* mRenderer;
		fr::InputManager mInputManager;
		fr::ScenesManager* mScenesManager;
	};
}


