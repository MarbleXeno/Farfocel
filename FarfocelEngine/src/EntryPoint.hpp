/*
    An entry point of the program. Here's the main function. It's here to move it to the Farfocel's side.
*/

#pragma once
#include "Farfocel/Application.hpp"

extern fr::Application* fr::initApplication();

int main(int argc, char** argv)
{
    fr::Application* app = fr::initApplication();
    app->initAppLoop();
    delete app;
    return 0;
}