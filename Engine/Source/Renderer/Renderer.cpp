#include "JemPCH.h"

#include "Renderer.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <Core/Window/Window.h>
#include <Renderer/Font.h>
#include <Renderer/Texture.h>
#include <Renderer/Camera.h>
#include <Maths/Rectangle.h>

namespace Jem {

namespace Renderer {
    SDL_Renderer* renderer;
    Vector4d      clearColour;
    Camera        sceneCamera;

    Font*         defaultFont;
    Font*         font;

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

        defaultFont = new Font("C:\\Windows\\Fonts\\consolabab.ttf", 24, true);
        font = defaultFont;
    }

    // ==================
    // Jem::Renderer::Shutdown
    // ==================
    void Shutdown() {
        delete defaultFont;
        if (font != nullptr) {
            delete font; 
            font = nullptr;
        }
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
    void SetFont(Font* newFont) {
        font = newFont;
    }

    // ==================
    // Jem::Renderer::DrawString
    //
    // TODO: Add newline support.
    // ==================
    void DrawString(const Vector2d& position, const char* text, Font* font, const Vector4d& colour) {
        SDL_SetTextureColorMod(font->GetTextureAtlas()->GetRawTexture(), colour.x, colour.y, colour.z);

        SDL_Rect  dest;
        SDL_Rect  source;
        Rectangle sourceRect;
        int i = 0;
        int x = 1;
        const char* stringChar = text;

        // Loop through string.
        while (*stringChar != '\0') {
            // Don't render anything for space.
            if (*stringChar == 32) {
                x += int(font->GetGlyphClip(' ').size.x);
                stringChar++;
                continue;
            }

            sourceRect = font->GetGlyphClip(*stringChar);

            source.x = sourceRect.position.x;
            source.y = sourceRect.position.y;
            source.w = sourceRect.size.x;
            source.h = sourceRect.size.y;

            dest.w = source.w;
            dest.h = source.h;
            dest.x = position.x + x;
            dest.y = position.y;

            SDL_RenderCopy(renderer, font->GetTextureAtlas()->GetRawTexture(), &source, &dest);

            i++;
            x += source.w + 1; // Add some padding.
            stringChar++;
        }
    }

    // ==================
    // Jem::Renderer::DrawString
    //
    // Draws using the font set with SetFont, or uses the default font.
    // ==================
    void DrawString(const Vector2d& position, const char* text, const Vector4d& colour) {
        DrawString(position, text, font, colour);
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
    // Angles are in degrees.
    // ==================
    void DrawTexturedRectangle(const Vector2d& position, const Vector2d& size, Texture* texture,
                               bool clip, const Rectangle& clipRect,
                               double angle,
                               bool flipHorizontally, bool flipVertically) {


        Vector2d screenCoords = sceneCamera.CalculateScreenCoords(position);
        Vector2d screenSize   = sceneCamera.CalculateScreenSize(size);

        SDL_Rect rect;
        rect.x = screenCoords.x;
        rect.y = screenCoords.y;
        rect.w = screenSize.x;
        rect.h = screenSize.y;

        SDL_Rect  clipRectSDL;
        SDL_Rect* clipRectSDLPointer = &clipRectSDL;
        if (clip) {
            clipRectSDL.x = clipRect.position.x;
            clipRectSDL.y = clipRect.position.y;
            clipRectSDL.w = clipRect.size.x;
            clipRectSDL.h = clipRect.size.y;
        } else {
            clipRectSDLPointer = nullptr;
        }

        SDL_RendererFlip flip = SDL_FLIP_NONE;
        if (flipVertically && flipHorizontally)    flip = SDL_RendererFlip(SDL_FLIP_VERTICAL | SDL_FLIP_HORIZONTAL);
        else if (flipVertically)      flip = SDL_FLIP_VERTICAL;
        else if (flipHorizontally)    flip = SDL_FLIP_HORIZONTAL;

        SDL_Point centerPoint;
        centerPoint.x = 0.5 * rect.w;
        centerPoint.y = 0.5 * rect.h;

        SDL_RenderCopyEx(renderer, texture->GetRawTexture(), clipRectSDLPointer, &rect, angle, &centerPoint, flip);
    }
}

}