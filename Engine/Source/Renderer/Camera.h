#pragma once

#include <Core/Maths/Vector2d.h>

namespace Jem {

// ===============================================================================
//
//     Camera is just a position offset and a zoom.
//
// ===============================================================================
class Camera {
public:
                        Camera(Vector2d position = { 0.0, 0.0 }, float zoom = 1.0);

    Vector2d            CalculateScreenCoords(const Vector2d& worldCoords);
    Vector2d            CalculateScreenSize(const Vector2d& worldSize);

    Vector2d            position;
    float               zoom;
};

}