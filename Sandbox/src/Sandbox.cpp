/*
    An application created using Farfocel.
*/

#include "EntryPoint.hpp"
#include "Farfocel.hpp"

#include "AppStates/SandboxState.hpp"

namespace app
{
    class Sandbox : public fr::Application
    {
        public:
            Sandbox()
            {
                initWindow();
                
                //a little 'stress test'
                stateManager.add(std::make_unique<SandboxState>(stateManager, renderWindow));
                fr::InputManager::bindKeyboard(sf::Keyboard::D, false, [=]() {stateManager.popAll(); });
            }

            ~Sandbox()
            {
                
            }

            void update()
            {
                stateManager.stateUpdate(deltaTime);
            }

            void draw()
            {
                renderWindow.clear(sf::Color::Yellow);
                stateManager.stateDraw();
                renderWindow.display();
            }
    };
}

fr::Application* fr::initApplication()
{
    return new app::Sandbox();
}