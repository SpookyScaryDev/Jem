#include "JemPCH.h"

#include "Renderer.h"

#include <SDL.h>
#include <Core/Window/Window.h>

namespace Jem {

namespace Renderer {
    SDL_Renderer* renderer;
    Vector4d      clearColour;

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

        clearColour = Vector4d(0, 0, 0, 0);
    }

    // ==================
    // Jem::Renderer::Shutdown
    // ==================
    void Shutdown() {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    // ==================
    // Jem::Renderer::GetRawRenderer
    // ==================
    SDL_Renderer* GetRawRenderer() {
        return renderer;
    }

    // ==================
    // Jem::Renderer::SetClearColour
    // ==================
    void SetClearColour(const Vector4d& colour) {
        clearColour = colour;
    }

    // ==================
    // Jem::Renderer::Clear
    // ==================
    void Clear() {
        SDL_SetRenderDrawColor(renderer, int(clearColour.x), int(clearColour.y), int(clearColour.z), int(clearColour.w));
        SDL_RenderClear(renderer);
    }

    // ==================
    // Jem::Renderer::Refresh
    // ==================
    void Refresh() {
        SDL_RenderPresent(renderer);
    }

    // ==================
    // Jem::Renderer::DrawLine
    // ==================
    void DrawLine(const Vector2d& position1, const Vector2d& position2, const Vector4d& colour) {
        SDL_SetRenderDrawColor(renderer, colour.x, colour.y, colour.z, colour.w);
        SDL_RenderDrawLine(renderer, position1.x, position1.y, position2.x, position2.y);
    }

    // ==================
    // Jem::Renderer::DrawRectangle
    // ==================
    void DrawRectangle(const Vector2d& position, const Vector2d& size, const Vector4d& colour) {
        SDL_Rect rect;
        rect.x = position.x;
        rect.y = position.y;
        rect.w = size.x;
        rect.h = size.y;

        SDL_SetRenderDrawColor(renderer, colour.x, colour.y, colour.z, colour.w);
        SDL_RenderDrawRect(renderer, &rect);
    }

    // ==================
    // Jem::Renderer::DrawRectangle
    // ==================
    void DrawFilledRectangle(const Vector2d& position, const Vector2d& size, const Vector4d& colour) {
        SDL_Rect rect;
        rect.x = position.x;
        rect.y = position.y;
        rect.w = size.x;
        rect.h = size.y;

        SDL_SetRenderDrawColor(renderer, colour.x, colour.y, colour.z, colour.w);
        SDL_RenderFillRect(renderer, &rect);
    }

    // ==================
    // Jem::Renderer::DrawTexturedRectangle
    // ==================
    void DrawTexturedRectangle(const Vector2d& position, const Vector2d& size, Texture texture) {
        SDL_Rect rect;
        rect.x = position.x;
        rect.y = position.y;
        rect.w = size.x;
        rect.h = size.y;

        SDL_RenderCopy(renderer, texture.GetRawTexture(), nullptr, &rect);
    }
}

}