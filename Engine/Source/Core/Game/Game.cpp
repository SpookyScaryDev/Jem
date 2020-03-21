#include "JemPCH.h"

#include "Game.h"

#include <Core/Window/Window.h>
#include <Renderer/Renderer.h>
#include <SDL.h>
#include <Core/Input/Input.h>
#include <chrono>

namespace Jem {

Game* Game::mGame = nullptr;

// ==================
// Jem::Game::Game
// ==================
Game::Game(const char* name, int width, int height) {
    // Initialize singleton.
    if (mGame != nullptr) {
        JEM_CORE_ERROR("Game already exists. You can only create 1 Game");
    }
    mGame = this;

    Init(name, width, height);
}

// ==================
// Jem::Game::~Game
// ==================
Game::~Game() {
    Shutdown();
    mGame = nullptr;
}

// ==================
// Jem::Game::GetGame
// ==================
Game* Game::GetGame() {
    return mGame;
}

// ==================
// Jem::Game::Init
// ==================
void Game::Init(const char* name, int width, int height) const{
    Jem::Log::Init();

    JEM_CORE_MESSAGE("************************************************************");
    JEM_CORE_MESSAGE("Initializing Jem:");
    JEM_CORE_MESSAGE("************************************************************");
    JEM_CORE_MESSAGE("Game::Init: Initializing Subsystems");

    JEM_CORE_MESSAGE("SDL_Init: Initializing SDL2");
    SDL_Init(SDL_INIT_EVERYTHING);

    JEM_CORE_MESSAGE("InitWindow: Creating Window");
    Window::Init(name, width, height);

    JEM_CORE_MESSAGE("Renderer::Init: Initializing Renderer");
    Renderer::Init();

    JEM_CORE_MESSAGE("Input::Init: Initializing Input");
    Input::Init();

    JEM_CORE_MESSAGE("************************************************************");
}

// ==================
// Jem::Game::Shutdown
// ==================
void Game::Shutdown() const{
    Input::Shutdown();
    Renderer::Shutdown();
    Window::Destroy();
    SDL_Quit();
}

// ==================
// Jem::Game::Run
// ==================
void Game::Run() {
    while (mIsRunning) {
        JEM_CORE_MESSAGE("Running Application");

        // Get time.
        std::chrono::system_clock::time_point previousTime = std::chrono::system_clock::now();
        while (mIsRunning) {
            // Calculate elapsed time.
            std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - previousTime);
            previousTime = currentTime;

            // Update input manager.
            mIsRunning = Input::Update(); // TODO: Add event system.

            // Update using delta time.
            Update(elapsed.count());

            // Refresh Renderer.
            Renderer::Clear();
            Renderer::Refresh();
        };
    }
}

}