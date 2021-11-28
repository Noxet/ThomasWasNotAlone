workspace "Thomas"
    platforms { "Win64" }
    configurations {"Debug", "Release"}

    language "C++"
    cppdialect "C++20"

    filter "platforms:Win64"
        system "Windows"
        architecture "x64"

    filter "configurations:Debug"
        -- Add preprocessor definition DEBUG to compiler
        defines {"DEBUG"}
        -- Enable debugging symbols
        symbols "On"
    
    filter "configurations:Release"
        defines {"RELEASE"}
        -- Turn on dat optimization
        optimize "On"

outputdir = "%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}"

project "Thomas"
    location "src"
    kind "ConsoleApp"

    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir)

    pchheader "tpch.hpp"
	pchsource "src/tpch.cpp" -- Only used by MSVC

    files
    {
        "src/**.hpp",
        "src/**.cpp",
    }

    includedirs
    {
        "%{prj.location}",
        "vendor/SFML/install/include",
        --"vendor/spdlog/include",
    }

    libdirs
    {
        "vendor/SFML/install/lib"
    }

    postbuildcommands
    {
        ("{COPY} ../vendor/SFML/install/bin/*.dll " .. "../bin/" .. outputdir)
    }

    filter "configurations:Debug"
        links
        {
            "sfml-graphics-d.lib",
            "sfml-window-d.lib",
            "sfml-system-d.lib",
            -- audio stuff
            "sfml-audio-d.lib",
            "openal32.lib",
        }

    filter "configurations:Release"
        links
        {
            "sfml-graphics.lib",
            "sfml-window.lib",
            "sfml-system.lib",
            -- audio stuff
            "sfml-audio.lib",
            "openal32.lib",
        }
