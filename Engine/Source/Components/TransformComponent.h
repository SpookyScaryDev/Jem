#pragma once

#include <Core/Maths/Vector2d.h>

namespace Jem {

struct TransformComponent {
    Vector2d        position;
    Vector2d        scale;
    double          rotation = 0.0;
    Vector2d        center   = { 0.5, 0.5 };
};

}