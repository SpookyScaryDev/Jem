#pragma once

#include <Core/Maths/Vector2d.h>
#include <Core/Maths/Vector4d.h>
#include <sstream>

// Core log macros.
#define JEM_CORE_MESSAGE(...)     Jem::Console::Message("Core: ", __VA_ARGS__)
#define JEM_CORE_WARNING(...)     Jem::Console::Warning("Core: ", __VA_ARGS__)
#define JEM_CORE_ERROR(...)       Jem::Console::Error(  "Core: ", __VA_ARGS__); __debugbreak()

// Client log macros.              
#define JEM_MESSAGE(...)          Jem::Console::Message(__VA_ARGS__)
#define JEM_WARNING(...)          Jem::Console::Warning(__VA_ARGS__)
#define JEM_ERROR(...)            Jem::Console::Error(  __VA_ARGS__); __debugbreak()

namespace Jem {

namespace Console {
    extern bool         isShown;
    extern Vector2d     size;
    extern Vector4d     backgroundColour;
    extern int          textHeight;
    extern Vector4d     textColour;
    
    void                Init();
    void                Shutdown();

    void                Update();
    void                Draw();

    void                Toggle();

    void                Print(const char* message);

    template <typename ... Args>
    inline void Print(const Args& ... args) {
        // Unpack the args onto a stringstream.
        std::stringstream stream;
        (stream << ... << args);
        Print(stream.str().c_str());
    }

    template <typename ... Args>
    inline void Message(const Args& ... message) {
        textColour = { 100.0, 200.0, 100.0, 255.0 };
        Print(message...);
        textColour = { 255.0, 255.0, 255.0, 255.0 };
    }

    template <typename ... Args>
    inline void Warning(const Args& ... warning) {
        textColour = { 240.0, 200.0, 40.0, 255.0 };
        Print(warning...);
        textColour = { 255.0, 255.0, 255.0, 255.0 };
    }

    template <typename ... Args>
    inline void Error(const Args& ... error) {
        textColour = { 200.0, 100.0, 100.0, 255.0 };
        Print(error...);
        textColour = { 255.0, 255.0, 255.0, 255.0 };
    }
}

}