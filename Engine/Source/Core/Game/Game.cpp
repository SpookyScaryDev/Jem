#include "JemPCH.h"

#include "Game.h"

#include <Core/Window/Window.h>
#include <Core/Event/Event.h>
#include <Core/Event/EventDispatcher.h>
#include <Core/Event/MouseEvent.h>
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
    
    mIsRunning = true;

    Init(name, width, height);

    EventDispatcher::SetEventCallbackMethod(this, &Game::OnEvent);
}

// ==================
// Jem::Game::~Game
// ==================
Game::~Game() {
    Shutdown();
    mGame = nullptr;
}

// ==================
// Jem::Game::OnEvent
// ==================
void Game::OnEvent(Event* event) {
    switch (event->GetType()) {
        case EventType::WindowClose:
            // Window closed, so stop the game.
            JEM_CORE_MESSAGE("Window Closed");
            mIsRunning = false;
            break;
    }
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
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        JEM_CORE_ERROR("SDL_Init: Failed to initialize SDL2 - ", SDL_GetError());
    }

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
    JEM_CORE_MESSAGE("Shutting down engine.");

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
            Input::Update();

            // Update using delta time.
            Update(elapsed.count());

            // Refresh Renderer.
            Renderer::Refresh();
        };
    }
}

}