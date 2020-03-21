#include "JemPCH.h"

#include "Renderer.h"

#include <SDL.h>
#include <Core/Window/Window.h>

namespace Jem {

namespace Renderer {
    SDL_Renderer* renderer;

    // ==================
    // Jem::Renderer::Init
    // ==================
    void Init() {
        renderer = SDL_CreateRenderer(Window::rawSDLWindow,
            -1,
            SDL_RENDERER_ACCELERATED |
            SDL_RENDERER_PRESENTVSYNC
        );

        if (renderer == nullptr) {
            // The renderer could not be created.
            JEM_CORE_ERROR("Renderer::Init: Failed to create renderer - ", SDL_GetError());
        }
    }

    // ==================
    // Jem::Renderer::Shutdown
    // ==================
    void Shutdown() {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    void SetClearColour(int r, int g, int b) {
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    }

    // ==================
    // Jem::Renderer::Clear
    // ==================
    void Clear() {
        SDL_RenderClear(renderer);
    }

    // ==================
    // Jem::Renderer::Refresh
    // ==================
    void Refresh() {
        SDL_RenderPresent(renderer);
    }
}

}