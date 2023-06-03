#pragma once
#include <vector>
#include <iostream>
#include <unordered_map>
#include <cstdint>

#include <SFML/Graphics.hpp>

namespace fr{
    class Window{
        public:
            Window();
            ~Window();

            void CreateView(const std::string& id, const sf::Vector2f& centerPosition, const sf::Vector2f& size);
            void SetView(const std::string& id);
            void RemoveView(const std::string& id);

            sf::View& GetView(const std::string& id);

            void Create();
            void Create(const std::string& windowTitle, const float& windowWidth, const float& windowHeight, const uint16_t& maxFramerate, const sf::ContextSettings& contextSettings = sf::ContextSettings());

            void SetMaxFPS(const uint16_t& maxFramerate);
            const uint16_t& GetWindowMaxFramerate();

            void SetIcon(const sf::Image& icon);

            const bool PoolEvents();

            void UpdateDeltaTime();
            const float& GetDeltaTimeFloat();
            sf::Time GetDeltaTime();

            void ResizeView(const sf::Vector2u& size);
            const sf::Vector2f GetViewSize();

            sf::RenderWindow& GetSFMLWindow();
            sf::Event& GetEvent();
        private:
            bool mInit;

            std::unordered_map<std::string, sf::View> mViews;
            sf::View* mCurrentView;

            
            sf::Event mEvent;
            sf::RenderWindow mSFMLWindow;
            uint16_t mWindowMaxFramerate;
    
            sf::Clock mDeltaClock;
            float mDeltaTime;
    };
}
