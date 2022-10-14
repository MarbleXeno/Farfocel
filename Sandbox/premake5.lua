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
        symbols "On"

        if os.host() == "windows" then
            defines {"SFML_STATIC"}
            includedirs
            {
                "%{wks.location}/Farfocel/include/",
                "%{wks.location}/Farfocel/libs/SFML/include"
            }
            libdirs
            {
                "%{wks.location}/Farfocel/libs/SFML/lib",
                "%{wks.location}/Farfocel/libs/SFML/lib/Debug"
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
                "Farfocel"
            }
        end

        if os.host() == "linux" then
            includedirs
            {
                "%{wks.location}/Farfocel/include/"
            }
            links
            {
                "sfml-graphics",
                "sfml-window",
                "sfml-audio",
                "sfml-system",
                "Farfocel"
            }
        end
    
        if os.host() == "macosx" then
            includedirs
            {
                "%{wks.location}/Farfocel/include/"
            }
            links
            {
                "sfml-graphics",
                "sfml-window",
                "sfml-audio",
                "sfml-system",
                "Farfocel"
            }
        end

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"
    
        if os.host() == "windows" then
            defines {"SFML_STATIC"}
            includedirs
            {
                "%{wks.location}/Farfocel/include/",
                "%{wks.location}/Farfocel/libs/SFML/include"
            }
            libdirs
            {
                "%{wks.location}/Farfocel/libs/SFML/lib",
                "%{wks.location}/Farfocel/libs/SFML/lib/Release"
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
                "Farfocel"
            }
        end

        if os.host() == "linux" then
            includedirs
            {
                "%{wks.location}/Farfocel/include/"
            }
            links
            {
                "sfml-graphics",
                "sfml-window",
                "sfml-audio",
                "sfml-system",
                "Farfocel"
            }
        end
    
        if os.host() == "macosx" then
            includedirs
            {
                "%{wks.location}/Farfocel/include/"
            }
            links
            {
                "sfml-graphics",
                "sfml-window",
                "sfml-audio",
                "sfml-system",
                "Farfocel"
            }
        end 
