/*
	Name:
	EntryPoint

	Description:
	Consists of a main function. It's here, where the programs starts.
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