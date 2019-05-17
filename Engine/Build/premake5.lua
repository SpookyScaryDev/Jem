
workspace "Jem"
    location "../../"

    architecture "x64"
    startproject "Sandbox"
    
    configurations {
        "Debug",
        "Development",
        "Ship"
    }

include "Jem/Jem.lua"

group "Examples"
include "Sandbox/Sandbox.lua"