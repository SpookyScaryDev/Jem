#include "JemPCH.h"

#include "Window.h"

#include <SDL.h>


namespace Jem {

namespace Window {
    SDL_Window* rawSDLWindow;
    int         windowWidth;
    int         windowHeight;

    // ==================
    // Jem::Window::Init
    // ==================
    void Init(const char* name, int width, int height) {
        windowWidth = width;
        windowHeight = height;

        rawSDLWindow = SDL_CreateWindow(name,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            width,
            height,
            SDL_WINDOW_SHOWN
        );

        if (rawSDLWindow == nullptr) {
            // The window could not be created.
            JEM_CORE_ERROR("InitWindow: Failed to create window - ", SDL_GetError());
        }
    }

    // ==================
    // Jem::Window::Destroy
    // ==================
    void Destroy() {
        SDL_DestroyWindow(rawSDLWindow);
    }

    // ==================
    // Jem::Window::GetWidth
    // ==================
    int GetWidth() {
        return windowWidth;
    }

    // ==================
    // Jem::Window::GetHeight
    // ==================
    int GetHeight() {
        return windowHeight;
    }
}

}