#include "JemPCH.h"

#include "Renderer.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <Core/Window/Window.h>
#include <Renderer/Texture.h>
#include <Renderer/Camera.h>

namespace Jem {

namespace Renderer {
    SDL_Renderer* renderer;
    Vector4d      clearColour;
    Camera        sceneCamera;

    TTF_Font*     font;

    // ==================
    // Jem::Renderer::Init
    // ==================
    void Init() {
        renderer = SDL_CreateRenderer(Window::rawSDLWindow,
            -1,
            SDL_RENDERER_ACCELERATED
        );

        if (renderer == nullptr) {
            // The renderer could not be created.
            JEM_CORE_ERROR("Renderer::Init: Failed to create renderer - ", SDL_GetError());
        }

        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

        SDL_RendererInfo rendererInfo;
        SDL_GetRendererInfo(renderer, &rendererInfo);
        JEM_CORE_MESSAGE("Renderer API: ", rendererInfo.name);

        clearColour = Vector4d(0, 0, 0, 0);
        SetFont("C:\\Windows\\Fonts\\consola.ttf", 15);
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
    // Jem::Renderer::BeginScene
    // ==================
    void BeginScene(const Camera& camera) {
        sceneCamera = camera;
    }

    // ==================
    // Jem::Renderer::EndScene
    // ==================
    void EndScene() {
        sceneCamera = { {0.0, 0.0}, 1.0 };
    }


    // ==================
    // Jem::Renderer::SetFont
    // ==================
    void SetFont(const char* name, unsigned int size) {
        font = TTF_OpenFont(name, size);
        JEM_CORE_ASSERT(font, "Renderer::SetFont: Failed to load font ", name);
    }

    // ==================
    // Jem::Renderer::DrawString
    // ==================
    void DrawString(const Vector2d& position, const char* text, const Vector4d& colour) {
        int text_width;
        int text_height;
        SDL_Surface* surface;
        SDL_Color textColor = { colour.x, colour.y, colour.z, colour.w };
        SDL_Rect rect;

        surface = TTF_RenderText_Blended(font, text, textColor);
        SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
        text_width = surface->w;
        text_height = surface->h;
        SDL_FreeSurface(surface);
        rect.x = position.x;
        rect.y = position.y;
        rect.w = text_width;
        rect.h = text_height;

        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }

    // ==================
    // Jem::Renderer::DrawLine
    // ==================
    void DrawLine(const Vector2d& position1, const Vector2d& position2, const Vector4d& colour) {
        Vector2d screenCoords1 = sceneCamera.CalculateScreenCoords(position1);
        Vector2d screenCoords2 = sceneCamera.CalculateScreenCoords(position2);

        SDL_SetRenderDrawColor(renderer, colour.x, colour.y, colour.z, colour.w);
        SDL_RenderDrawLine(renderer, screenCoords1.x, screenCoords1.y, screenCoords2.x, screenCoords2.y);
    }

    // ==================
    // Jem::Renderer::DrawRectangle
    // ==================
    void DrawRectangle(const Vector2d& position, const Vector2d& size, const Vector4d& colour) {
        Vector2d screenCoords = sceneCamera.CalculateScreenCoords(position);
        Vector2d screenSize   = sceneCamera.CalculateScreenSize(size);

        SDL_Rect rect;
        rect.x = screenCoords.x;
        rect.y = screenCoords.y;
        rect.w = screenSize.x;
        rect.h = screenSize.y;

        SDL_SetRenderDrawColor(renderer, colour.x, colour.y, colour.z, colour.w);
        SDL_RenderDrawRect(renderer, &rect);
    }

    // ==================
    // Jem::Renderer::DrawRectangle
    // ==================
    void DrawFilledRectangle(const Vector2d& position, const Vector2d& size, const Vector4d& colour) {
        Vector2d screenCoords = sceneCamera.CalculateScreenCoords(position);
        Vector2d screenSize = sceneCamera.CalculateScreenSize(size);

        SDL_Rect rect;
        rect.x = screenCoords.x;
        rect.y = screenCoords.y;
        rect.w = screenSize.x;
        rect.h = screenSize.y;

        SDL_SetRenderDrawColor(renderer, colour.x, colour.y, colour.z, colour.w);
        SDL_RenderFillRect(renderer, &rect);
    }

    // ==================
    // Jem::Renderer::DrawTexturedRectangle
    //
    // Draws the whole texture by default.
    // Angles are in degrees.
    // ==================
    void DrawTexturedRectangle(const Vector2d& position, const Vector2d& size, Texture* texture,
                               const Vector2d& topLeft, const Vector2d& bottomRight,
                               double angle, const Vector2d& center,
                               bool flipHorizontally, bool flipVertically) {


        Vector2d screenCoords = sceneCamera.CalculateScreenCoords(position);
        Vector2d screenSize   = sceneCamera.CalculateScreenSize(size);

        SDL_Rect rect;
        rect.x = screenCoords.x;
        rect.y = screenCoords.y;
        rect.w = screenSize.x;
        rect.h = screenSize.y;

        SDL_Rect clip;
        clip.x = texture->GetWidth()  * topLeft.x;
        clip.y = texture->GetHeight() * topLeft.y;
        clip.w = texture->GetWidth()  * (bottomRight.x - topLeft.x);
        clip.h = texture->GetHeight() * (bottomRight.y - topLeft.y);

        SDL_RendererFlip flip = SDL_FLIP_NONE;
        if (flipVertically && flipHorizontally)    flip = SDL_RendererFlip(SDL_FLIP_VERTICAL | SDL_FLIP_HORIZONTAL);
        else if (flipVertically)      flip = SDL_FLIP_VERTICAL;
        else if (flipHorizontally)    flip = SDL_FLIP_HORIZONTAL;

        SDL_Point centerPoint;
        centerPoint.x = center.x * rect.w;
        centerPoint.y = center.y* rect.h;

        SDL_RenderCopyEx(renderer, texture->GetRawTexture(), &clip, &rect, angle, &centerPoint, flip);
    }
}

}