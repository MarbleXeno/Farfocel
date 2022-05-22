project "FarfocelEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/%{cfg.buildcfg}")
    objdir ("bin-obj/%{cfg.buildcfg}")

    files
    {
        "include/**.hpp",
        "src/**.cpp"
    }

    filter "configurations:Debug"
        defines {"DEBUG"}
        defines {"FR_DEBUG"}  
        symbols "On"

        -- SFML libraries should be linked statically only on Windows. On other systems, you should link to them dynamically.
        if os.host() == "windows" then
            defines {"SFML_STATIC"}
            includedirs
            {
                "include/",
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
                "ws2_32"
            }
        end

        if os.host() == "linux" then
            includedirs
            {
                "include/"
            }
            links
            {
                "sfml-graphics",
                "sfml-window",
                "sfml-audio",
                "sfml-system"
            }
        end

        if os.host() == "macosx" then
            includedirs
            {
                "include/"
            }
            links
            {
                "sfml-graphics",
                "sfml-window",
                "sfml-audio",
                "sfml-system"
            }
        end
        
    filter "configurations:Release"
        defines {"NDEBUG"}
        defines "FR_RELEASE"
        optimize "On"
        
        if os.host() == "windows" then
            defines {"SFML_STATIC"}
            includedirs
            {
                "include/",
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
                "ws2_32"
            }
        end
        
        if os.host() == "linux" then
            includedirs
            {
                "include/"
            }
            links
            {
                "sfml-graphics",
                "sfml-window",
                "sfml-audio",
                "sfml-system"
            }
        end

        if os.host() == "macosx" then
            includedirs
            {
                "include/"
            }
            links
            {
                "sfml-graphics",
                "sfml-window",
                "sfml-audio",
                "sfml-system"
            }
        end