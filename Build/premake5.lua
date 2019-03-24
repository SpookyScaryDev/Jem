
workspace "Jem"
    location "../"

    architecture "x64"
    startproject "Sandbox"
    
    configurations {
        "Debug",
        "Development",
        "Ship"
    }

include "../Engine/Build"
include "../Examples/Sandbox/Build"