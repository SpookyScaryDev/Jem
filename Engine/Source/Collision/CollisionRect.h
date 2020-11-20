#pragma once

#include <Core/Maths/Vector2d.h>

namespace Jem {


// ===============================================================================
//
//     Represents a rectangular collision body. Can use a rectangular polygon or
//     an AABB depending on if the rectangle is rotated.
//
// ===============================================================================
struct CollisionRect {
    Vector2d           position;
    Vector2d           size;
    double             rotation = 0.0;
    Vector2d           center = { 0.5, 0.5 }; // 0-1 Fraction of width and height
};

}