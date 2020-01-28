#include "JemPCH.h"

#include "Game.h"

#include <Core/Window/Window.h>
#include <SDL.h>

namespace Jem {
	Game* Game::mGame = nullptr;

	Game::Game(const char* name, int width, int height) {
		if (mGame != nullptr) {
			JEM_CORE_ERROR("Game already exists. You can only create 1 Game");
		}

		// TODO: move to init function.
		JEM_CORE_MESSAGE("************************************************************");
		JEM_CORE_MESSAGE("Initializing Jem:");
		JEM_CORE_MESSAGE("************************************************************");
		JEM_CORE_MESSAGE("Initializing SDL2");
		SDL_Init(SDL_INIT_EVERYTHING);

		mGame = this;
		JEM_CORE_MESSAGE("Creating Window");
		InitWindow(name, width, height);
		JEM_CORE_MESSAGE("************************************************************");
	}
	
	Game::~Game() {
		mGame = nullptr;
	}

	Game* Game::GetGame(){
		return mGame;
	}

	void Game::Run() {
		JEM_CORE_MESSAGE("Running Application");
		std::cin.get();
	}
}