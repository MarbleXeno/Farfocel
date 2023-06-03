#pragma once
#include <iostream>
#include <memory>

#include <imgui.h>
#include <imgui-SFML.h>

#include "Farfocel/Core/Window.hpp"

#include "Farfocel/Common/EventManager.hpp"
#include "Farfocel/Common/InputManager.hpp"
#include "Farfocel/Common/ResourceManager.hpp"
#include "Farfocel/Common/Console.hpp"

#include "Farfocel/Common/GUI/Style.hpp"
#include "Farfocel/Common/GUI/Container.hpp"
#include "Farfocel/Common/GUI/Widgets/Text.hpp"
#include "Farfocel/Common/GUI/Widgets/Button.hpp"

namespace fr{
    class Runtime{
    public:
        Runtime();
        ~Runtime();

        // Init Window and Farfocel using default variables
        void Init();
        void Init(const std::string& windowTitle, const uint16_t& windowWidth, const uint16_t& windowHeight, const uint16_t& maxFramerate, const sf::ContextSettings& contextSettings = sf::ContextSettings());
        void StartUpdateLoop();

        virtual void Start() = 0;
        virtual void HandleEvents() = 0;
        virtual void HandleInput() = 0;
        virtual void Update() = 0;
        //virtual void FixedUpdate();
        virtual void Render() = 0;

    protected:
        void SetDevMode(const bool& mode);

        fr::Window window;
    private:
        bool mDevMode;
        void InitFarfocel();

        sf::Event* mEvent;
        sf::RenderWindow* mSFMLWindow;

        fr::ResourceManager mResourcesMan;
        fr::InputManager mInputMan;

        frg::Style mStyle;
        frg::Text mText;
        frg::Text mText2;
        frg::Text mText3;

        frg::Button mButton;

        frg::Container mContainer;
    };

    std::unique_ptr<Runtime> GetApp();
}
