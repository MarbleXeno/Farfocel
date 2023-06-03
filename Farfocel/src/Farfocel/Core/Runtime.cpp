 #include "Farfocel/Core/Runtime.hpp"

namespace fr{
    Runtime::Runtime()
            : mDevMode(true), mEvent(nullptr), mSFMLWindow(nullptr), mResourcesMan(), mInputMan(), mStyle("style"), mText("text"),mText2("text"),mText3("text"), mButton("button"), mContainer("cont"){
    }

    Runtime::~Runtime(){
        ImGui::SFML::Shutdown();
    }

    void Runtime::Init(){
#ifdef _WIN32
        system("cls");
#endif

        window.Create();

        InitFarfocel();

        Start();
    }

    void Runtime::Init(const std::string& windowTitle, const uint16_t& windowWidth, const uint16_t& windowHeight, const uint16_t& maxFramerate, const sf::ContextSettings& contextSettings){
#ifdef _WIN32
        system("cls");
#endif

        window.Create(windowTitle, windowWidth, windowHeight, maxFramerate, contextSettings);

        InitFarfocel();
        Start();
    }

    void Runtime::InitFarfocel() {
        mSFMLWindow = &window.GetSFMLWindow();
        mEvent = &window.GetEvent();

        ImGui::SFML::Init(window.GetSFMLWindow());
        fr::Console::AddLog("TO-DO: Add lua support and simple engine commands", fr::LogLevel::MESSAGE);

        // Event Manager setup
        fr::EventManager::Init(window);

        fr::EventManager::AddBinding(sf::Event::Closed, true, [&]() { window.GetSFMLWindow().close(); });
        fr::EventManager::AddBinding(sf::Event::Resized, true, [&]() { window.ResizeView({ window.GetEvent().size.width, window.GetEvent().size.height }); });

        fr::EventManager::AddBinding(sf::Event::Resized, true, [&]() {mContainer.Update(window.GetViewSize());});

        mInputMan = fr::InputManager(*mSFMLWindow);
        mInputMan.Bind(sf::Keyboard::Tilde, false, [=](){ fr::Console::show = !fr::Console::show; });

        mResourcesMan.LoadFont("font", "res/fonts/font.ttf");

        //mStyle.fText = &mResourcesMan.GetFont("font");

        //mText.SetStyle(mStyle);
        //mText.SetString("TextONE");
        //mText.SetCharacterSize(30.f);
        //mText.SetOutlineSize(2.f);
        //mText.SetOrigin(frg::WidgetOrigin::TOP_LEFT);
        //mText.SetPosition({1280.f/2.f,720.f/2.f});

        //mText2.SetStyle(mStyle);
        //mText2.SetString("TextTWOTWO");
        //mText2.SetCharacterSize(30.f);
        //mText2.SetOutlineSize(2.f);
        //mText2.SetOrigin(frg::WidgetOrigin::TOP_LEFT);
        //mText2.SetPosition({1280.f/2.f,720.f/2.f});

        //mText3.SetStyle(mStyle);
        //mText3.SetString("TextTHREETHREETHREE");
        //mText3.SetCharacterSize(30.f);
        //mText3.SetOutlineSize(2.f);
        //mText3.SetOrigin(frg::WidgetOrigin::TOP_LEFT);
        //mText3.SetPosition({1280.f/2.f,720.f/2.f});

        //mButton.SetStyle(mStyle);
        //mButton.SetTextString("CLOSE");
        //mButton.SetTextSize({30.f,50.f,50.f});

        //mButton.SetOrigin(frg::WidgetOrigin::CENTER_MIDDLE);
        //mButton.SetPosition({1280.f/2.f,720.f/2.f});

        //mButton.SetCallback([&](){window.GetSFMLWindow().close();});

        //mContainer.BreakRow();
        //mContainer.AddWidget(mText3);
        //mContainer.AddWidget(mText2);
        //mContainer.AddWidget(mButton);
        //mContainer.BreakRow();
        //mContainer.AddWidget(mText);

        //mContainer.SetPosition({1280.f/2.f,720.f/2.f});
        //mContainer.SetPosition(frg::ContainerAlignment::CENTER_MIDDLE);
        //mContainer.SetOrigin(frg::ContainerAlignment::CENTER_MIDDLE);
        //mContainer.SetVerticalAlignment(frg::WidgetAlignment::HALF);
        //mContainer.SetHorizontalAlignment(frg::WidgetAlignment::HALF);

        //mContainer.SetMargins({20.f,20.f});

        fr::EventManager::AddEventFunction([&](){ImGui::SFML::ProcessEvent(window.GetSFMLWindow(), window.GetEvent());});

        //fr::EventManager::AddEventFunction([&](){if(mButton.GetGlobalRect().contains(mInputMan.GetMouseRelativeCoords())){
        //    mButton.SetState(frg::ButtonState::BUTTON_HOVERED);
        //    mContainer.Update(window.GetViewSize());
        //    if(mInputMan.IsPressed(sf::Mouse::Left)){
        //        mButton.SetState(frg::ButtonState::BUTTON_PRESSED);
        //        mContainer.Update(window.GetViewSize());
        //    }
        //    else if(fr::EventManager::IsActive(sf::Event::MouseButtonReleased) && mEvent->mouseButton.button == sf::Mouse::Left){
        //        mButton.Exec();
        //    }
        //}
        //else{
        //    mButton.SetState(frg::ButtonState::BUTTON_NEUTRAL);
        //    mContainer.Update(window.GetViewSize());
        //};});
    }

    void Runtime::StartUpdateLoop(){
        while (window.GetSFMLWindow().isOpen()){
            //Events
            fr::EventManager::PoolEvents();
            HandleEvents();

            //Input
            mInputMan.UpdateKeyboard();
            HandleInput();

            //Updates
            ImGui::SFML::Update(window.GetSFMLWindow(), window.GetDeltaTime());
            Update();


            //Rendering
            window.GetSFMLWindow().clear(sf::Color::Red);

            //Scene rendering
            Render();

            if(mDevMode)
                fr::Console::Draw();
            ImGui::SFML::Render(window.GetSFMLWindow());


            window.GetSFMLWindow().display();
        }
    }

    void Runtime::SetDevMode(const bool &mode) {
        mDevMode = mode;
    }

}
