#include "Farfocel/Core/Renderer.hpp"

namespace fr{
    Renderer::Renderer()
        : mEvent(), mRenderWindow(), mWindowMaxFramerate(144), mDeltaClock(), mDeltaTime(0.00694f), mCurrentView(nullptr) {
    
    }

    Renderer::~Renderer(){

    }

    void Renderer::CreateView(const std::string& id, const sf::Vector2f& centerPosition, const sf::Vector2f& size){
        if (mViews.count(id)) {
		    std::cout << "void fr::Renderer::CreateView(const std::string& id, const sf::Vector2f& centerPosition, const sf::Vector2f& size) --> A view with the same ID is already defined\n";
		    return;
	    }

	    mViews[id] = sf::View(centerPosition, size);
    }

    void Renderer::SetView(const std::string& id){
        if (!mViews.count(id)) {
		    std::cout << "void fr::Renderer::SetView(const std::string & id) --> Couldn't find a view with given id\n";
		    return;
	    }

	    mRenderWindow.setView(mViews[id]);
	    mCurrentView = &mViews[id];
    }

    void Renderer::RemoveView(const std::string& id){
        if (!mViews.count(id)) {
            std::cout << "void fr::Renderer::RemoveView(const std::string& id) --> Couldn't find a view with given id";
            return;
        }

        if (&mViews[id] == mCurrentView) {
            std::cout << "void fr::Renderer::RemoveView(const std::string& id) --> A view with given id is currently in use by the render window";
            return;
        }

        mViews.erase(id);
    }

    sf::View& Renderer::GetView(const std::string& id){
        if (!mViews.count(id)) {
            std::cout << "sf::View& fr::Renderer::GetView(const std::string& id) --> Couldn't find a view with given id. Returning a default view\n";
            
            if (!mViews.count("DEFAULT_VIEW")) {
                mViews["DEFAULT_VIEW"] = sf::View({1280.f/2,720.f/2}, { 1280.f, 720.f });
            }

            return mViews["DEFAULT_VIEW"];
        }

        return mViews[id];
    }

    void Renderer::CreateWindow(){
        mRenderWindow.create(sf::VideoMode(1280.f, 720.f), "Something");
        

        CreateView("DEFAULT_VIEW", {1280.f/2,720.f/2}, {1280.f, 720.f});
        SetView("DEFAULT_VIEW");

        SetWindowMaxFramerate(144);
    }

    void Renderer::CreateWindow(const std::string& windowTitle, const float& windowWidth, const float& windowHeight, const uint16_t& maxFramerate, const sf::ContextSettings& contextSettings){
        mRenderWindow.create(sf::VideoMode(windowWidth, windowHeight), windowTitle, contextSettings.Core);

        CreateView("DEFAULT_VIEW", {0,0}, {windowWidth, windowHeight});
        SetView("DEFAULT_VIEW");  

        SetWindowMaxFramerate(maxFramerate);
    }

    void Renderer::SetWindowMaxFramerate(const uint16_t& maxFramerate){
        mWindowMaxFramerate = maxFramerate;
        mRenderWindow.setFramerateLimit(mWindowMaxFramerate);
    }

    const uint16_t& Renderer::GetWindowMaxFramerate(){
        return mWindowMaxFramerate;
    }

    sf::RenderWindow& Renderer::GetRenderWindow(){
        return mRenderWindow;
    }

    sf::Event& Renderer::GetWindowEvent(){
        return mEvent;
    }
    
    void Renderer::UpdateDeltaTime(){
        mDeltaTime = mDeltaClock.restart().asSeconds();
        if (mDeltaTime > 1.0f / mWindowMaxFramerate) {
            mDeltaTime = 1.0f / mWindowMaxFramerate;
        }
    }

    const float& Renderer::GetDeltaTimeFloat(){
        return mDeltaTime;
    }

    sf::Time& Renderer::GetDeltaTime()
    {
        return mDeltaClock.getElapsedTime();
    }
    
    void Renderer::ResizeView(const sf::Vector2u& size){
        for (auto& view : mViews) {
            view.second.setSize(size.x, size.y);
            
        }

        mCurrentView->setSize(size.x, size.y);
        mRenderWindow.setView(*mCurrentView);
    }

    const sf::Vector2u Renderer::GetViewSize()
    {
        return sf::Vector2u(mCurrentView->getSize().x, mCurrentView->getSize().y);
    }
}