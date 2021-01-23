#pragma once

#include <Core/Maths/Vector2d.h>
#include <Core/Maths/Vector4d.h>
#include <Renderer/Font.h>
#include <Renderer/Texture.h>
#include <Renderer/Camera.h>
#include <Core/Maths/Rectangle.h>

struct SDL_Renderer;

namespace Jem {

namespace Renderer { 
    void                    Init();
    void                    Shutdown();

    SDL_Renderer*           GetRawRenderer();

    void                    SetClearColour(const Vector4d& colour);
    void                    Clear();                             // Clear screen to the clear colour.
    void                    Refresh();

    void                    BeginScene(const Camera& camera);
    void                    EndScene();

    void                    SetFont(const Font& newFont);
    void                    DrawString(const Vector2d& position, const char* text, const Vector4d& colour = { 255.0, 255.0, 255.0, 255.0 });
    void                    DrawString(const Vector2d& position, const char* text, Font* font, const Vector4d& colour = { 255.0, 255.0, 255.0, 255.0 });

    void                    DrawLine(const Vector2d& position1, const Vector2d& position2, const Vector4d& colour);
    void                    DrawRectangle(const Vector2d& position, const Vector2d& size, const Vector4d& colour);
    void                    DrawFilledRectangle(const Vector2d& position, const Vector2d& size, const Vector4d& colour);
    void                    DrawTexturedRectangle(const Vector2d& position, const Vector2d& size, Texture* texture,
                                                  bool clip = false, const Rectangle& clipRegion = {},
                                                  double angle = 0.0,                       // Angle is in degrees.
                                                  bool flipHorizontally = false, bool flipVertically = false);
}

}