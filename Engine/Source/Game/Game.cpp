#include "JemPCH.h"

#include "Game/Game.h"
#include <Game/World.h>
#include <GameObject/Component.h>

namespace Jem {
	Game* Game::mGame = nullptr;

	Game::Game() :
		mWorld()
	{
		if (mGame != nullptr) {
			JEM_CORE_ERROR("Game already exists. You can only create 1 Game");
		}

		mGame = this;
	}
	
	Game::~Game() {}

	Game* Game::GetGame(){
		return mGame;
	}

	void Game::Run() {
		JEM_CORE_MESSAGE("Running Application");
		std::cin.get();
	}

}