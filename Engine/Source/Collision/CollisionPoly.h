#pragma once
#include <Core/Maths/Vector2d.h>

namespace Jem {


// ===============================================================================
//
//     Simple 4 sided polygon, used for representing rotated squares.
//
// ===============================================================================
struct Poly {
    Vector2d    position;
    Vector2d    positions[4];
};

}