#pragma once

#include <Core/Maths/Vector2d.h>
#include <Core/Maths/Rectangle.h>

namespace Jem {


// ===============================================================================
//
//     Represents a rectangular collision body. Can use a rectangular polygon or
//     an AABB depending on if the rectangle is rotated.
//
// ===============================================================================
struct CollisionRect {
    Rectangle          rect = { { 0.0, 0.0 }, { 0.0 , 0.0 } };
    double             rotation = 0.0;
    Vector2d           center = { 0.5, 0.5 }; // 0-1 Fraction of width and height
};

}