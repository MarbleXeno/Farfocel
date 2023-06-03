#pragma once

#ifdef WIN32
    #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#include <memory>

#include "Farfocel/Core/Runtime.hpp"

extern std::unique_ptr<fr::Runtime> fr::GetApp();

int main(int argc, char* argv[])
{
    std::unique_ptr<fr::Runtime> app = fr::GetApp();
    return 0;
}