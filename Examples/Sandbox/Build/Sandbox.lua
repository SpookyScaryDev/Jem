
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
        
project "Sandbox"
    location      "../"
    kind          "ConsoleApp"
    language      "C++"
    staticruntime "On"

    characterset  "MBCS"    --Only needed for my rubbish logging library.
                            --TODO: Replace my rubbish logging library!

    targetdir ("../Binaries/" .. outputdir)
    objdir    ("../Intermediate/" .. outputdir)

    files {
        "../Source/**.h",
        "../Source/**.cpp",
    }

    includedirs {
        "../../../Engine/Source"
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