#pragma once

#include <Core/Maths/Vector2d.h>

namespace Jem {


// ===============================================================================
//
//     Simple AABB collision rect.
//
// ===============================================================================
struct AABB {
    Vector2d            min;
    Vector2d            max;
};

}