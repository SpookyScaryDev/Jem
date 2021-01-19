#pragma once

#include <Renderer/Texture.h>
#include <Core/Maths/Vector2d.h>
#include <Core/Maths/Rectangle.h>

namespace Jem {

// ===============================================================================
//
//     Component containing a texture and data about how to render it.
//
// ===============================================================================
struct TextureComponent {
    Texture*        texture;
    bool            isFlippedVertical   = false;
    bool            isFlippedHorizontal = false;
    bool            drawRegion          = false; // Whether the clipping rectangle should be used.
    Rectangle       clipRegion          = { { 0.0, 0.0 }, { 0.0, 0.0 } };
};

}