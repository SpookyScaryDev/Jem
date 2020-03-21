#include "JemPCH.h"

#include "Input.h"

#include <SDL.h>

#include <Core/Input/KeyCodes.h>
#include <Core/Input/MouseCodes.h>

namespace Jem {

namespace Input {
    const Uint8* keyboardState;
    Uint8        mouseState;
    int          mouseXPosition; // TODO: Replace with a vector maybe.
    int          mouseYPosition;

    // ==================
    // Jem::Input::Init
    // ==================
    void Init() {
        keyboardState = SDL_GetKeyboardState(nullptr);
    }

    // ==================
    // Jem::Input::Shutdown
    // ==================
    void Shutdown() {
        keyboardState = nullptr;
    }

    // ==================
    // Jem::Input::Update
    // ==================
    bool Update() {
        SDL_Event event;
        while ((SDL_PollEvent(&event)) != 0) { // TODO: Add mouse scrolling maybe.
            if (event.type == SDL_QUIT) {
                return false;
            }
        }
        mouseState = SDL_GetMouseState(&mouseXPosition, &mouseYPosition);

        return true;
    }

    // ==================
    // Jem::Input::IsKeyPressed
    // ==================
    bool IsKeyPressed(KeyCode key) {
        return keyboardState[static_cast<Uint8>(key)];
    }

    // ==================
    // Jem::Input::IsMouseButtonPressed
    // ==================
    bool IsMouseButtonPressed(MouseCode button) {
        return mouseState & SDL_BUTTON(static_cast<int>(button));
    }

    // ==================
    // Jem::Input::GetMousePosition
    // ==================
    std::pair<int, int> GetMousePosition() {
        return std::make_pair(mouseXPosition, mouseYPosition);
    }
}

}