
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    
project "Jem"
    location      "../"
    kind          "SharedLib"
    language      "C++"
    staticruntime "off"

    characterset  "MBCS"    --Only needed for my rubbish logging library.
                            --TODO: Replace my rubbish logging library!

    targetdir ("../Binaries/" .. outputdir)
    objdir    ("../Intermediate/" .. outputdir)

    pchheader "JemPCH.h"
    pchsource "../Source/Core/JemPCH.cpp"

    files {
        "../Include/**.h",
        "../Source/**.cpp"
    }

    includedirs {
        "../Include/Core",    --Needed for pch.
        "../Include"
    }

    filter "system:windows"
        cppdialect    "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "JEM_WINDOWS",
            "JEM_DLL"
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