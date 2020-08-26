#include "JemPCH.h"
#include "Camera.h"

#include <Core/Maths/Vector2d.h>
#include <Core/Window/Window.h>

namespace Jem {

Camera::Camera(Vector2d position, float zoom) :
    position(position),
    zoom(zoom) {};

Vector2d Camera::CalculateScreenCoords(const Vector2d& worldCoords) {
    Vector2d screenCoords;

    screenCoords.x = Window::GetWidth()  / 2 - (Window::GetWidth()  / 2 - worldCoords.x - position.x) * zoom;
    screenCoords.y = Window::GetHeight() / 2 - (Window::GetHeight() / 2 - worldCoords.y - position.y) * zoom;
    return screenCoords;
}

Vector2d Camera::CalculateScreenSize(const Vector2d& worldSize) {
    Vector2d screenSize;

    screenSize.x = worldSize.x * zoom;
    screenSize.y = worldSize.y * zoom;
    return screenSize;
}

}