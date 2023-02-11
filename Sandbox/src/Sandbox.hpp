#pragma once
#include <Farfocel/Core/Runtime.hpp>
#include <Farfocel/Managers/AnimationManager.hpp>
#include <Farfocel/Managers/ResourcesManager.hpp>
#include <Farfocel/Managers/InputManager.hpp>
#include <Farfocel/Managers/ScenesManager.hpp>

#include "Scenes/Scene.hpp"

namespace sb{
    class Sandbox : public fr::Runtime{
        public:
            Sandbox();
            ~Sandbox();

            void Start();
            void HandleEvents();
            void HandleInput();
            void Update();
            void Render();


        private:
            sf::Sprite mBackground;
            sf::Sprite mLogo;
            fr::ResourcesManager mResourceManager;
            fr::AnimationManager mAnimationManager;
            fr::InputManager mInputManager;

            fr::ScenesManager mScenesManager;
    };
} // namespace sb
