project "FarfocelEngine"
    kind "StaticLib"
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

    includedirs
    {
        "../SFML/include"
    }

    defines
    {
        "SFML_STATIC"
    }

    filter "configurations:Debug"
        defines {"DEBUG"}
        defines "FR_DEBUG"  
        symbols "On"
        libdirs
        {
            "../SFML/lib",
            "../SFML/lib/Debug"
        }

        links
        {
            "sfml-graphics-s-d",
            "sfml-window-s-d",
            "sfml-system-s-d",
            "sfml-audio-s-d",
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
            "ws2_32"
        }

    filter "configurations:Release"
        defines {"NDEBUG"}
        defines "FR_RELEASE"
        optimize "On"
        libdirs
        {
            "../SFML/lib",
            "../SFML/lib/Release"
        }

        links
        {
            "sfml-graphics-s",
            "sfml-window-s",
            "sfml-system-s",
            "sfml-audio-s",
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
            "ws2_32"
        }
