#include "Application.hpp"
using namespace fr;

Application::Application()  : renderWindow(), m_windowFPSLimit(144)
{

}

Application::~Application()
{
    fr::InputManager::clearAllBindings();
    fr::EventManager::clearAllBindings();
    std::string logFileDirectory = LOG_FILE_DEF_DIRECTORY;
    fr::Log::writeLogsToFile(logFileDirectory);
}

void Application::init(const std::string& windowTitle, const std::uint16_t& resolutionX, const std::uint16_t& resolutionY)
{
    system("cls");

    renderWindow.create(sf::VideoMode(resolutionX, resolutionY), windowTitle, sf::Style::Close);
    renderWindow.setView(sf::View(sf::FloatRect(0.f,0.f,resolutionX,resolutionY)));

    fr::EventManager::init(renderWindow);
    fr::EventManager::addBinding(sf::Event::Closed, false, [&](){renderWindow.close();});

    fr::InputManager::init(renderWindow);

    fr::Log::print(fr::LogColor::Cyan, "Initialized Farfocel Engine! \n");
    fr::Log::print(fr::LogColor::Cyan, "Below you'll find some useful debug info. \n");
    fr::Log::print(fr::LogColor::Cyan, "After the app closes the file with the logs is created where the executable is.\n");
    fr::Log::print(fr::LogColor::Reset, "\n");
}

void Application::initWindow()
{
    init(WINDOW_DEF_TITLE, WINDOW_DEF_RES_X, WINDOW_DEF_RES_Y);    
}

void Application::initWindow(const std::string& windowTitle, const std::uint16_t& resolutionX, const std::uint16_t& resolutionY)
{
    init(windowTitle, resolutionX, resolutionY);   
}

void Application::initAppLoop()
{
    while (renderWindow.isOpen())
    {
        fr::EventManager::update();
        fr::InputManager::update();
        update();
        draw();
    }
}

void Application::setWindowFramerateLimit(const std::uint16_t& fpsLimit)
{
    m_windowFPSLimit = fpsLimit;    
}