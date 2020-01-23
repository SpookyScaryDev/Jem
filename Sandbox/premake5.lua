
projectdir = ""
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
        
project "Sandbox"
    location      (projectdir)
    kind          "ConsoleApp"
    language      "C++"
    staticruntime "On"

    targetdir (projectdir .. "Binaries/" .. outputdir)
    objdir    (projectdir .. "Intermediate/" .. outputdir)

    files {
        projectdir .. "Source/**.h",
        projectdir .. "Source/**.cpp",
    }

    includedirs {
        "../Engine/Source"
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