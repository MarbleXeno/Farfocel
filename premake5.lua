workspace "Farfocel Application"
    require "cmake"
    architecture "x64"
    startproject "Sandbox"
    configurations
    {
        "Debug",
        "Release"
    }

    include "FarfocelEngine"
    include "Sandbox"