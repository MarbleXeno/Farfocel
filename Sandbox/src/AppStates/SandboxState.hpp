/*
    A state managed by the State Manager.
*/

#pragma once
#include "Farfocel.hpp"

namespace app
{
    class SandboxState : public fr::IState
    {
        public:
            SandboxState(fr::StateManager& stateManager, sf::RenderWindow& renderWindow);
            ~SandboxState();

            void handleEvents();
            void handleInput();

            void update();
            void draw();
        private:
            fr::StateManager& m_stateManager;
            sf::RenderWindow& m_renderWindow;
            fr::ResourceManager m_resourceManager;

            sf::Sprite m_sprite;
            sf::Sprite m_secondSprite;
    };
}