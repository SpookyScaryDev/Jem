#include "JemPCH.h"
#include "BasicCameraController.h"

#include <Renderer/Camera.h>
#include <Core/Input/Input.h>
#include <Core/Input/MouseCodes.h>

namespace Jem {

void BasicCameraController(Camera& camera, float moveSpeed, float zoomSpeed) {
    static bool     wasMousePressed = false;
    static Vector2d lastMousePosition;
    static Vector2d lastMouseWheelPosition = Input::GetMouseScrollWheelPosition();

    if (Input::IsMouseButtonPressed(MouseCode::BUTTON_MIDDLE)) {
        if (!wasMousePressed) {
            lastMousePosition = Input::GetMousePosition();
            wasMousePressed = true;
        }

        camera.position += ((Input::GetMousePosition() - lastMousePosition) / camera.zoom) * moveSpeed;
        lastMousePosition = Input::GetMousePosition();

    }
    else {
        wasMousePressed = false;
    }

    float oldZoom = camera.zoom;
    camera.zoom += (Input::GetMouseScrollWheelPosition().y - lastMouseWheelPosition.y) * zoomSpeed;
    if (camera.zoom <= 0.0) camera.zoom = oldZoom;

    lastMouseWheelPosition = Input::GetMouseScrollWheelPosition();
}

}