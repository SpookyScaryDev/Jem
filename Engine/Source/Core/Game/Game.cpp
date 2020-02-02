#include "JemPCH.h"

#include "Game.h"

#include <Core/Window/Window.h>
#include <Renderer/Renderer.h>
#include <SDL.h>

namespace Jem {
	Game* Game::mGame = nullptr;

	Game::Game(const char* name, int width, int height) {
		if (mGame != nullptr) {
			JEM_CORE_ERROR("Game already exists. You can only create 1 Game");
		}

		mGame = this;

		Init(name, width, height);
	}
	
	Game::~Game() {
		mGame = nullptr;
	}

	Game* Game::GetGame(){
		return mGame;
	}

	void Game::Init(const char* name, int width, int height) {
		Jem::Log::Init();

		JEM_CORE_MESSAGE("************************************************************");
		JEM_CORE_MESSAGE("Initializing Jem:");
		JEM_CORE_MESSAGE("************************************************************");
		JEM_CORE_MESSAGE("Game::Init: Initializing Subsystems");

		JEM_CORE_MESSAGE("SDL_Init: Initializing SDL2");
		SDL_Init(SDL_INIT_EVERYTHING);

		JEM_CORE_MESSAGE("InitWindow: Creating Window");
		InitWindow(name, width, height);

		JEM_CORE_MESSAGE("Renderer::Init: Initializing Renderer");
		Renderer::Init();

		JEM_CORE_MESSAGE("************************************************************");
	}

	void Game::Run() {
		JEM_CORE_MESSAGE("Running Application");

		// Renderer Test - pure evil!
		while (true) {
			double range = 500;
			for (double i = 0; i < range; i++) {
				//we want to normalize ratio so that it fits in to 6 regions
				//where each region is 256 units long
				int normalized = int(i / range * 256 * 6);

				//find the distance to the start of the closest region
				int x = normalized % 256;

				int red = 0, grn = 0, blu = 0;
				switch (normalized / 256)
				{
				case 0: red = 255;      grn = x;        blu = 0;       break;//red
				case 1: red = 255 - x;  grn = 255;      blu = 0;       break;//yellow
				case 2: red = 0;        grn = 255;      blu = x;       break;//green
				case 3: red = 0;        grn = 255 - x;  blu = 255;     break;//cyan
				case 4: red = x;        grn = 0;        blu = 255;     break;//blue
				case 5: red = 255;      grn = 0;        blu = 255 - x; break;//magenta
				}

				Renderer::SetClearColour(red, grn, blu);

				Renderer::Clear();
				Renderer::Refreash();
			}
		}

		std::cin.get();
	}
}