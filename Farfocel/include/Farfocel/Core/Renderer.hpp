#pragma once
#include <vector>
#include <iostream>
#include <unordered_map>

#include <SFML/Graphics.hpp>

namespace fr{
    class Renderer{
        public:
            Renderer();
            ~Renderer();

            void CreateView(const std::string& id, const sf::Vector2f& centerPosition, const sf::Vector2f& size);
            void SetView(const std::string& id);
            void RemoveView(const std::string& id);

            sf::View& GetView(const std::string& id);

            void CreateWindow();
            void CreateWindow(const std::string& windowTitle, const float& windowWidth, const float& windowHeight, const uint16_t& maxFramerate, const sf::ContextSettings& contextSettings = sf::ContextSettings());

            void SetWindowMaxFramerate(const uint16_t& maxFramerate);
            const uint16_t& GetWindowMaxFramerate();

            sf::RenderWindow& GetRenderWindow();

            sf::Event& GetWindowEvent();

            void UpdateDeltaTime();
            const float& GetDeltaTimeFloat();
            sf::Time& GetDeltaTime();

            void ResizeView(const sf::Vector2u& size);
            const sf::Vector2u GetViewSize();

        private:
            std::unordered_map<std::string, sf::View> mViews;
            sf::View* mCurrentView;

            
            sf::Event mEvent;
            sf::RenderWindow mRenderWindow;
            uint16_t mWindowMaxFramerate;
    
            sf::Clock mDeltaClock;
            float mDeltaTime;
    };
}