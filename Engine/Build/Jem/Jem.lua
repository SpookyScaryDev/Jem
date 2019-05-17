
projectdir = "../../"
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    
project "Jem"
    location      "../../"
    kind          "StaticLib"
    language      "C++"
    staticruntime "On"

    characterset  "MBCS"    --Only needed for my rubbish logging library.
                            --TODO: Replace my rubbish logging library!

    targetdir (projectdir .. "Binaries/" .. outputdir)
    objdir    (projectdir .. "Intermediate/" .. outputdir)

    pchheader "JemPCH.h"
    pchsource (projectdir .. "Source/Core/JemPCH.cpp")

    files {
        projectdir .. "Source/**.h",
        projectdir .. "Source/**.cpp"
    }

    includedirs {
        projectdir .. "Source/Core",    --Needed for pch.
        projectdir .. "Source"
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