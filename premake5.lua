
workspace "Jem"
    location ""

    architecture "x64"
    startproject "Sandbox"
    
    configurations {
        "Debug",
        "Development",
        "Ship"
    }

include "Engine/premake5.lua"
include "Sandbox/premake5.lua"