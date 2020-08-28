#pragma once

#include <Core/Input/KeyCodes.h>
#include <Core/Input/MouseCodes.h>
#include <Core/Maths/Vector2d.h>

namespace Jem {

namespace Input {
    void                  Init();
    void                  Shutdown();
    void                  Update();
    bool                  IsKeyPressed(KeyCode key);
    bool                  IsMouseButtonPressed(MouseCode key);
    Vector2d              GetMousePosition();
    Vector2d              GetMouseScrollWheelPosition();
}

}