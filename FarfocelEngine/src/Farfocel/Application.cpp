#include "Application.hpp"
#ifdef FR_DEBUG
    #include <SFML/OpenGL.hpp>
#endif // FR_DEBUG

using namespace fr;

Application::Application()  : renderWindow(), m_windowFPSLimit(144)
{

}

Application::~Application()
{
    fr::InputManager::clearAllBindings();

    std::string logFileDirectory = LOG_FILE_DEF_DIRECTORY;
    fr::Log::writeLogsToFile(logFileDirectory);
}

void Application::init(const std::string& windowTitle, const std::uint16_t& resolutionX, const std::uint16_t& resolutionY)
{
#ifdef _WIN32
    system("cls");
#endif // _WIN32

    fr::Log::print(fr::LogColor::Red, true, "Welcome to Strawberry Fields, forever..");
    fr::Log::printSpace();

#ifdef FR_DEBUG
    fr::Log::printDebug(fr::LogColor::White, true, "You're in a DEBUG mode.");
#endif // FR_DEBUG

    m_startupConfigurationFile.init(CFG_FILE_DEF_DIRECTORY);

    renderWindow.create(sf::VideoMode(resolutionX, resolutionY), windowTitle, sf::Style::Close);
    renderWindow.setView(sf::View(sf::FloatRect(0.f,0.f,resolutionX,resolutionY)));

    setWindowFramerateLimit(std::stoi(m_startupConfigurationFile.getEntry("fps_limit")));

    fr::Log::print(fr::LogColor::White, true, "FPS Limit: " + std::to_string(m_windowFPSLimit));

    fr::InputManager::init(renderWindow);
    fr::EventManager::init(renderWindow, evnt);

    fr::EventManager::addBinding(sf::Event::Closed, false, [=]() {renderWindow.close(); });
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
        fr::EventManager::updateEvents();

        fr::InputManager::updateMouse();
        fr::InputManager::updateKeyboard();

        update();
        draw();
    }
}

void Application::setWindowFramerateLimit(const std::uint16_t& fpsLimit)
{
    m_windowFPSLimit = fpsLimit;
    renderWindow.setFramerateLimit(m_windowFPSLimit);
}
