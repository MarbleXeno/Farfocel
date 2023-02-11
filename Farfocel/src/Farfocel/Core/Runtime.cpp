#include "Farfocel/Core/Runtime.hpp"

namespace fr{
    Runtime::Runtime()
        : mRenderWindow(nullptr), mEvent(nullptr){

    }

    Runtime::~Runtime(){
        ImGui::SFML::Shutdown();
    }

    void Runtime::Init(){
        #ifdef _WIN32
	        system("cls");
        #endif

        renderer.CreateWindow();

        InitFarfocel();

        Start();
    }

    void Runtime::Init(const std::string& windowTitle, const uint16_t& windowWidth, const uint16_t& windowHeight, const uint16_t& maxFramerate, const sf::ContextSettings& contextSettings){
        #ifdef _WIN32
	        system("cls");
        #endif

        renderer.CreateWindow(windowTitle, windowWidth, windowHeight, maxFramerate, contextSettings);

        InitFarfocel();
        Start();
    }

    void Runtime::InitFarfocel() {
        mRenderWindow = &renderer.GetRenderWindow();
        mEvent = &renderer.GetWindowEvent();

        // Event Manager setup
        eventManager = fr::EventManager(renderer.GetRenderWindow(), renderer.GetWindowEvent());
        
        eventManager.AddBinding(sf::Event::Closed, true, [=]() { renderer.GetRenderWindow().close(); });
        eventManager.AddBinding(sf::Event::Resized, true, [=]() { renderer.ResizeView({ renderer.GetWindowEvent().size.width, renderer.GetWindowEvent().size.height }); });
        
        ImGui::SFML::Init(renderer.GetRenderWindow());
        
    }

    void Runtime::StartUpdateLoop(){
        while (renderer.GetRenderWindow().isOpen()){

            eventManager.Update();
            HandleEvents();

            HandleInput();

            Update();
            ImGui::SFML::Update(renderer.GetRenderWindow(), renderer.GetDeltaTime());

            renderer.GetRenderWindow().clear(sf::Color::Cyan);
            Render();

            ImGui::SFML::Render(renderer.GetRenderWindow());
            renderer.GetRenderWindow().display();
        }
    }
    
}