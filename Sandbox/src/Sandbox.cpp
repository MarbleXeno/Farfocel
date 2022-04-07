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
                stateManager.addTop(new SandboxState(stateManager, renderWindow));
            }

            ~Sandbox()
            {
                
            }

            void update()
            {
                stateManager.update();
            }

            void draw()
            {
                renderWindow.clear(sf::Color::Yellow);
                stateManager.draw();
                renderWindow.display();
            }
    };
}

fr::Application* fr::initApplication()
{
    return new app::Sandbox();
}