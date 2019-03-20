
workspace "Jem"
    location "../"

	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Development",
		"Ship"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    
project "Jem"
    location      "../Engine"
    kind          "SharedLib"
    language      "C++"
    staticruntime "off"

    characterset  "MBCS"    --Only needed for my rubbish logging library.
                            --TODO: Replace my rubbish logging library!

    targetdir ("../Engine/Binaries/" .. outputdir)
    objdir    ("../Engine/Intermediate/" .. outputdir)

    pchheader "JemPCH.h"
    pchsource "../Engine/Source/Core/JemPCH.cpp"

    files {
        "../Engine/Include/**.h",
        "../Engine/Source/**.cpp"
    }

    includedirs {
        "../Engine/Include/Core",    --Needed for pch.
        "../Engine/Include"
    }

    filter "system:windows"
        cppdialect    "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "JEM_WINDOWS",
            "JEM_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} \"../Examples/Binaries/" .. outputdir .. "/Sandbox/\" ")
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
        
project "Sandbox"
    location      "../Examples/Sandbox"
    kind          "ConsoleApp"
    language      "C++"
    staticruntime "off"

    characterset  "MBCS"    --Only needed for my rubbish logging library.
                            --TODO: Replace my rubbish logging library!

    targetdir ("../Examples/Binaries/" .. outputdir .. "/Sandbox")
    objdir    ("../Examples/Intermediate/" .. outputdir .. "/Sandbox")

    files {
        "../Examples/Sandbox/Source/**.h",
        "../Examples/Sandbox/Source/**.cpp",
    }

    includedirs {
        "../Engine/Include"
    }

    links {
        "Jem"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines {
            "JEM_WINDOWS"
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


