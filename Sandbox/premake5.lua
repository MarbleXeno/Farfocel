project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/%{cfg.buildcfg}")
    objdir ("bin-obj/%{cfg.buildcfg}")

    files
    {
        "src/**.hpp",
        "src/**.cpp"
    }

    filter "configurations:Debug"
        defines {"DEBUG"}
        defines {"FR_DEBUG"}  
        symbols "On"

        filter "system:Windows"
            defines {"SFML_STATIC"}
            includedirs
            {
                "%{wks.location}/FarfocelEngine/src",
                "%{wks.location}/SFML/include"
            }
            libdirs
            {
                "%{wks.location}/SFML/lib",
                "%{wks.location}/SFML/lib/Debug"
            }
            links
            {
                "sfml-graphics-s-d",
                "sfml-window-s-d",
                "sfml-audio-s-d",
                "sfml-system-s-d",
                "opengl32",
                "openal32",
                "freetype",
                "winmm",
                "gdi32",
                "flac",
                "vorbisenc",
                "vorbisfile",
                "vorbis",
                "ogg",
                "ws2_32",
                "FarfocelEngine"
            }

        filter "system:Linux"
            includedirs
            {
                "%{wks.location}/FarfocelEngine/src"
            }
            links
            {
                "sfml-graphics",
                "sfml-window",
                "sfml-audio",
                "sfml-system",
                "FarfocelEngine"
            }
    
        filter "system:Mac"
            includedirs
            {
                "%{wks.location}/FarfocelEngine/src"
            }
            links
            {
                "sfml-graphics",
                "sfml-window",
                "sfml-audio",
                "sfml-system",
                "FarfocelEngine"
            }
    
    filter "configurations:Release"
        defines {"NDEBUG"}
        defines "FR_RELEASE"
        optimize "On"
    
        filter "system:Windows"
            defines {"SFML_STATIC"}
            includedirs
            {
                "%{wks.location}/FarfocelEngine/src",
                "%{wks.location}/SFML/include"
            }
            libdirs
            {
                "%{wks.location}/SFML/lib",
                "%{wks.location}/SFML/lib/Release"
            }
            links
            {
                "sfml-graphics-s",
                "sfml-window-s",
                "sfml-audio-s",
                "sfml-system-s",
                "opengl32",
                "openal32",
                "freetype",
                "winmm",
                "gdi32",
                "flac",
                "vorbisenc",
                "vorbisfile",
                "vorbis",
                "ogg",
                "ws2_32",
                "FarfocelEngine"
            }

        filter "system:Linux"
            includedirs
            {
                "%{wks.location}/FarfocelEngine/src"
            }
            links
            {
                "sfml-graphics",
                "sfml-window",
                "sfml-audio",
                "sfml-system",
                "FarfocelEngine"
            }
    
        filter "system:Mac"
            includedirs
            {
                "%{wks.location}/FarfocelEngine/src"
            }
            links
            {
                "sfml-graphics",
                "sfml-window",
                "sfml-audio",
                "sfml-system",
                "FarfocelEngine"
            }