#pragma once

#include <Renderer/Texture.h>
#include <Core/Maths/Vector2d.h>

namespace Jem {

struct SpriteComponent {
    Texture*        texture;
    bool            isFlippedVertical   = false;
    bool            isFlippedHorizontal = false;
    Vector2d        topLeft             = {0.0, 0.0};
    Vector2d        bottomRight         = {1.0, 1.0 };
};

}