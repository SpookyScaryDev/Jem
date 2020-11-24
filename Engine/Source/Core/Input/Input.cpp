#include "JemPCH.h"

#include "Input.h"

#include <SDL.h>

#include <Core/Input/KeyCodes.h>
#include <Core/Input/MouseCodes.h>

#include <Core/Event/EventDispatcher.h>
#include <Core/Event/WindowEvent.h>
#include <Core/Event/KeyEvent.h>
#include <Core/Event/MouseEvent.h>
#include <Core/Event/TextEvent.h>

#include <Core/Maths/Vector2d.h>

namespace Jem {

namespace Input {
    const Uint8* keyboardState;
    Uint8        mouseState;
    int          mouseXPosition; // TODO: Replace with a vector maybe.
    int          mouseYPosition;
    Vector2d     mouseScrollWheelPosition = { 0.0, 0.0 };

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
    void Update() {
        SDL_Event event;
        while ((SDL_PollEvent(&event)) != 0) { // TODO: Add mouse scrolling maybe. Also get rid of the news.
            switch (event.type) {
                case SDL_QUIT:
                    EventDispatcher::DispatchEvent(new WindowCloseEvent());
                    break;

                case SDL_KEYDOWN:
                    EventDispatcher::DispatchEvent(new KeyPressedEvent((KeyCode)event.key.keysym.scancode));
                    break;

                case SDL_KEYUP:
                    EventDispatcher::DispatchEvent(new KeyReleasedEvent((KeyCode)event.key.keysym.scancode));
                    break;

                case SDL_MOUSEMOTION:
                    EventDispatcher::DispatchEvent(new MouseMovedEvent(event.motion.x, event.motion.y));
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    EventDispatcher::DispatchEvent(new MouseButtonPressedEvent((MouseCode)event.button.button));
                    break;

                case SDL_MOUSEBUTTONUP:
                    EventDispatcher::DispatchEvent(new MouseButtonReleasedEvent((MouseCode)event.button.button));
                    break;

                case SDL_MOUSEWHEEL:
                    EventDispatcher::DispatchEvent(new MouseScrolledEvent(event.wheel.x, event.wheel.y));
                    mouseScrollWheelPosition.x += event.wheel.x;
                    mouseScrollWheelPosition.y += event.wheel.y;
                    break;

                case SDL_TEXTINPUT:
                    EventDispatcher::DispatchEvent(new TextInputEvent(event.text.text));
                    break;
            }
        }
        mouseState = SDL_GetMouseState(&mouseXPosition, &mouseYPosition);
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
    Vector2d GetMousePosition() {
        return Vector2d(mouseXPosition, mouseYPosition);
    }

    // ==================
    // Jem::Input::GetMouseScrollWheelPosition
    // ==================
    Vector2d GetMouseScrollWheelPosition() {
        return mouseScrollWheelPosition;
    }
}

}