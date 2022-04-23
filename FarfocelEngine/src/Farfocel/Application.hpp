/*
    Name:
    Application

    Description:
    A runtime. Inherit from it and voilà - now you can make AAA games, FUCKING gigantic apps and more!
*/

#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Utils/StateManager/StateManager.hpp"
#include "Utils/EventManager.hpp"

#include "Utils/InputManager.hpp"
#include "Utils/EventManager.hpp"

#include "Utils/Log.hpp"

#include "Utils/StartupConfigurationFile.hpp"

#include "Utils/AnimationManager/Animation.hpp"

namespace fr
{
    #define WINDOW_DEF_RES_X 640
    #define WINDOW_DEF_RES_Y 480
    #define WINDOW_DEF_TITLE "Farfocel Application"
    #define LOG_FILE_DEF_DIRECTORY "log_file.txt"
    #define CFG_FILE_DEF_DIRECTORY "startup_cfg.txt"

    class Application
    {
        public:
            Application();
            virtual ~Application();

            void initWindow();
            void initWindow(const std::string& windowTitle, const std::uint16_t& resolutionX, const std::uint16_t& resolutionY);
            void initAppLoop();
            void setWindowFramerateLimit(const std::uint16_t& fpsLimit);

            virtual void update() = 0;
            virtual void draw() = 0;

        protected:
            sf::RenderWindow renderWindow;

            fr::StateManager stateManager;

        private:
            void init(const std::string& windowTitle, const std::uint16_t& resolutionX, const std::uint16_t& resolutionY);
            fr_util::StartupConfigurationFile m_startupConfigurationFile;
            std::uint16_t m_windowFPSLimit;
            sf::Event evnt;

    };

    Application* initApplication();
}

