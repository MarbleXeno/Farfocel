#pragma once
#include "Farfocel/Core/Window.hpp"

namespace frg{
    class GUIManager{
    public:
        GUIManager();
        GUIManager(fr::Window& window);
        ~GUIManager();



    private:
        fr::Window* mWindow;
    };
}