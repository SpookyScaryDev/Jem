
workspace "Jem"
    location "../"

    architecture "x64"
    startproject "Sandbox"
    
    configurations {
        "Debug",
        "Development",
        "Ship"
    }

include "../Engine/Build/Jem.lua"

group "Examples"
include "../Examples/Sandbox/Build/Sandbox.lua"