#pragma once 

#include <Core/Game/Game.h>
#include <Core/Log/Log.h>

namespace Jem {
	extern Game* CreateGame();
}

int main(int argc, char **argv) {
	Jem::Log::Init();                  // TODO: Init function / constructor in application.

	Jem::Game* game = Jem::CreateGame();
	game->Run();
	delete game;

	return 0;
}