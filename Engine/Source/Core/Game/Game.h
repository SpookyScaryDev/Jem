#pragma once

#include <Core/Window/Window.h>

namespace Jem {

// ===============================================================================
//
//     Base Game Class.
//     To be subclassed by the client and run by Jem Engine.
//     Game is a singleton - you can use the GetGame method to return the instance.
//
// ===============================================================================
class Game {
public:
                   Game(const char* name, int width, int height); // Calls Init.
    virtual        ~Game();                                       // Calls Shutdown.
    static Game*   GetGame();                                     // Retrieve the static game instance.
    void           Run();

protected:
    virtual void   Update(double deltaTime) {};

private:
    void           Init(const char* name, int width, int height) const;
    void           Shutdown() const;

    bool           mIsRunning = true;
    static Game*   mGame;
};

}