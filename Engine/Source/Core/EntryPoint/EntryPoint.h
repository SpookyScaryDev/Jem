#pragma once 

#include <Core/Game/Game.h>

namespace Jem {

// To be implemented by the client: Returns a Game subclass to be used be the Jem Engine.
extern Game* CreateGame();

}

// ==================
// main
// ==================
int main(int argc, char **argv) {
    // Runs a Game subclass provided by CreateGame.
    // Entry point for the Jem Engine
    Jem::Game* game = Jem::CreateGame();
    game->Run();
    delete game;

    return 0;
}