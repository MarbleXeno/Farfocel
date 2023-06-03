#include "Farfocel/Core/Window.hpp"

namespace fr{
    Window::Window()
        : mEvent(), mSFMLWindow(), mWindowMaxFramerate(144), mDeltaClock(), mDeltaTime(0.00694f), mCurrentView(nullptr), mInit(false) {
    
    }

    Window::~Window(){

    }

    void Window::CreateView(const std::string& id, const sf::Vector2f& centerPosition, const sf::Vector2f& size){
        if (mViews.count(id)) {
		    std::cout << "void fr::Window::CreateView(const std::string& id, const sf::Vector2f& centerPosition, const sf::Vector2f& size) --> A view with the same ID is already defined\n";
		    return;
	    }

	    mViews[id] = sf::View(centerPosition, size);
    }

    void Window::SetView(const std::string& id){
        if (!mViews.count(id)) {
		    std::cout << "void fr::Window::SetView(const std::string & id) --> Couldn't find a view with given id\n";
		    return;
	    }

	    mSFMLWindow.setView(mViews[id]);
	    mCurrentView = &mViews[id];
    }

    void Window::RemoveView(const std::string& id){
        if (!mViews.count(id)) {
            std::cout << "void fr::Window::RemoveView(const std::string& id) --> Couldn't find a view with given id";
            return;
        }

        if (&mViews[id] == mCurrentView) {
            std::cout << "void fr::Window::RemoveView(const std::string& id) --> A view with given id is currently in use by the render window";
            return;
        }

        mViews.erase(id);
    }

    sf::View& Window::GetView(const std::string& id){
        if (!mViews.count(id)) {
            std::cout << "sf::View& fr::Window::GetView(const std::string& id) --> Couldn't find a view with given id. Returning a default view\n";
            
            if (!mViews.count("DEFAULT_VIEW")) {
                mViews["DEFAULT_VIEW"] = sf::View({1280.f/2,720.f/2}, { 1280.f, 720.f });
            }

            return mViews["DEFAULT_VIEW"];
        }

        return mViews[id];
    }

    void Window::Create(){
        mSFMLWindow.create(sf::VideoMode(1280.f, 720.f), "Farfocel");
        

        CreateView("DEFAULT_VIEW", {1280.f/2,720.f/2}, {1280.f, 720.f});
        SetView("DEFAULT_VIEW");

        SetMaxFPS(144);
        mInit = true;
    }

    void Window::Create(const std::string& windowTitle, const float& windowWidth, const float& windowHeight, const uint16_t& maxFramerate, const sf::ContextSettings& contextSettings){
        mSFMLWindow.create(sf::VideoMode(windowWidth, windowHeight), windowTitle, contextSettings.Core);

        CreateView("DEFAULT_VIEW", {0,0}, {windowWidth, windowHeight});
        SetView("DEFAULT_VIEW");

        SetMaxFPS(maxFramerate);

        mInit = true;
    }

    void Window::SetMaxFPS(const uint16_t& maxFramerate){
        mWindowMaxFramerate = maxFramerate;
        mSFMLWindow.setFramerateLimit(mWindowMaxFramerate);
    }

    const uint16_t& Window::GetWindowMaxFramerate(){
        return mWindowMaxFramerate;
    }

    void Window::SetIcon(const sf::Image &icon) {
        mSFMLWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    }

    const bool Window::PoolEvents()
    {
        return mSFMLWindow.pollEvent(mEvent);
    }

    sf::RenderWindow& Window::GetSFMLWindow(){
        return mSFMLWindow;
    }

    sf::Event& Window::GetEvent(){
        return mEvent;
    }

    void Window::UpdateDeltaTime(){
        mDeltaTime = mDeltaClock.restart().asSeconds();
        if (mDeltaTime > 1.0f / mWindowMaxFramerate) {
            mDeltaTime = 1.0f / mWindowMaxFramerate;
        }
    }

    const float& Window::GetDeltaTimeFloat(){
        return mDeltaTime;
    }

    sf::Time Window::GetDeltaTime()
    {
        return mDeltaClock.getElapsedTime();
    }

    void Window::ResizeView(const sf::Vector2u& size){
        for (auto& view : mViews) {
            view.second.setSize(size.x, size.y);
            view.second.setCenter(size.x/2,size.y/2);
        }

        mCurrentView->setSize(size.x, size.y);
        mCurrentView->setCenter(size.x/2, size.y/2);

        mSFMLWindow.setView(*mCurrentView);
    }

    const sf::Vector2f Window::GetViewSize()
    {
        return sf::Vector2f(mCurrentView->getSize().x, mCurrentView->getSize().y);
    }

}
