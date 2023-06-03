#pragma once
#include <iostream>
#include <Farfocel/Farfocel.hpp>
#include <imgui.h>

namespace vi {
    class Vifon : public fr::Runtime{
    public:
        Vifon();
        ~Vifon();

        void Start();
        void HandleEvents();
        void HandleInput();
        void Update();
        void Render();

    private:
        fr::ResourceManager mResourceManager;
        fr::InputManager mInputManager;

        frg::Container mContainer;
        frg::Style mStyle;

        frg::Text mText;
        frg::Text mText2;
        frg::Text mText3;
        frg::Button mButton;
    };
}

std::unique_ptr<fr::Runtime> fr::GetApp() {
    return std::make_unique<vi::Vifon>();
}