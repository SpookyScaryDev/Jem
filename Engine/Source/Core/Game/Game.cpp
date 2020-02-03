#include "JemPCH.h"

#include "Game.h"

#include <Core/Window/Window.h>
#include <Renderer/Renderer.h>
#include <SDL.h>
#include <Core/Input/Input.h>

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
		Shutdown();
		mGame = nullptr;
	}

	Game* Game::GetGame() {
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

		JEM_CORE_MESSAGE("Input::Init: Initializing Input");
		Input::Init();

		JEM_CORE_MESSAGE("************************************************************");
	}

	void Game::Shutdown() {  // Shutdown subsystems in reverse order.
		Input::Destroy();
		Renderer::Shutdown();
		DestroyWindow();
		SDL_Quit();
	}

	void Game::Run() {
		JEM_CORE_MESSAGE("Running Application");

		// Renderer Test - pure evil!
		int r = 0;
		int g = 0;
		int b = 0;
		while (true) {
			Input::Update();
			if (Input::IsKeyPressed(JEM_KEY_SPACE)) {
				JEM_CORE_WARNING("Space Key Pressed");

				r = (rand() % 255) + 1;
				g = (rand() % 255) + 1;
				b = (rand() % 255) + 1;
			}
			Renderer::SetClearColour(r, g, b);

			Renderer::Clear();
			Renderer::Refreash();
		}

		std::cin.get();
	}
}