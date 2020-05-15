#pragma once

#include <Core/Maths/Vector2d.h>
#include <Core/Maths/Vector4d.h>
#include <Renderer/Texture.h>

struct SDL_Renderer;

namespace Jem {

namespace Renderer { 
    void                    Init();
    void                    Shutdown();

    SDL_Renderer*           GetRawRenderer();

    void                    SetClearColour(const Vector4d& colour);
    void                    Clear();                             // Clear screen to the clear colour.
    void                    Refresh();

    void                    DrawLine(const Vector2d& position1, const Vector2d& position2, const Vector4d& colour);
    void                    DrawRectangle(const Vector2d& position, const Vector2d& size, const Vector4d& colour);
    void                    DrawFilledRectangle(const Vector2d& position, const Vector2d& size, const Vector4d& colour);
    void                    DrawTexturedRectangle(const Vector2d& position, const Vector2d& size, Texture texture);
}

}