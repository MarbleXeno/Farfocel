#pragma once
#include <iostream>

#include "Farfocel/Core/Renderer.hpp"

#include "Farfocel/Managers/EventManager.hpp"

#include <imgui.h>
#include <imgui-SFML.h>

namespace fr{
    class Runtime{
        public:
            Runtime();
            ~Runtime();

            // Init Window and Farfocel using default variables
            void Init();
            void Init(const std::string& windowTitle, const uint16_t& windowWidth, const uint16_t& windowHeight, const uint16_t& maxFramerate, const sf::ContextSettings& contextSettings = sf::ContextSettings());
            void StartUpdateLoop();

            virtual void Start() = 0;
            virtual void HandleEvents() = 0;
            virtual void HandleInput() = 0;
            virtual void Update() = 0;
            //virtual void FixedUpdate();
            virtual void Render() = 0;

        protected:
            fr::Renderer renderer;
            fr::EventManager eventManager;
        private:
            void InitFarfocel();

            sf::Event* mEvent;
            sf::RenderWindow* mRenderWindow;
        
    };
}