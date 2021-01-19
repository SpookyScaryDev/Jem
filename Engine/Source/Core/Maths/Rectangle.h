#pragma once

namespace Jem {

// ===============================================================================
//
//     Represents a rectangle with a position and height.
//     TODO: Add unions for Vector2d, ie. width and height.
//
// ===============================================================================
struct Rectangle {
    Vector2d            position;
    Vector2d            size;
};

}