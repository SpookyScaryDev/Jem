
projectdir = ""
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Vendor/SDL2/SDL2.lua"
include "Vendor/SDL2/SDL2main.lua"
    
project "Jem"
    location      (projectdir)
    kind          "StaticLib"
    language      "C++"
    staticruntime "On"

    targetdir (projectdir .. "Binaries/" .. outputdir)
    objdir    (projectdir .. "Intermediate/" .. outputdir)

    pchheader "JemPCH.h"
    pchsource (projectdir .. "Source/Core/JemPCH.cpp")

	links {
		"SDL2",
		"SDL2main",
        "SDL2_ttf"
	}

    files {
        projectdir .. "Source/**.h",
        projectdir .. "Source/**.cpp"
    }

    includedirs {
		"Vendor/SDL2/include",
        projectdir .. "Source/Core",    --Needed for pch.
        projectdir .. "Source",

		"Vendor/SDL_ttf/include"
    }

    libdirs {
        "Vendor/SDL_ttf/lib/x64"
    }

    filter "system:windows"
        cppdialect    "C++17"
        systemversion "latest"

        defines {
            "JEM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "JEM_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Development"
        defines "JEM_DEVELOPMENT"
        runtime "Release"
        optimize "On"

    filter "configurations:Ship"
        defines "JEM_SHIP"
        runtime "Release"
        optimize "Speed"
