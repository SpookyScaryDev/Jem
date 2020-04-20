#include "JemPCH.h"
#include "MouseEvent.h"

#include <Core/Event/Event.h>
#include <Core/Input/MouseCodes.h>

namespace Jem {
    // ==================
    // Jem::MouseMovedEvent::MouseMovedEvent
    // ==================
    MouseMovedEvent::MouseMovedEvent(int x, int y) :
        mMouseXPos(x),
        mMouseYPos(y) {}

    // ==================
    // Jem::MouseMovedEvent::GetType
    // ==================
    EventType MouseMovedEvent::GetType() const {
        return EventType::MouseMoved;
    }
    // ==================
    // Jem::MouseMovedEvent::GetXPos
    // ==================
    int MouseMovedEvent::GetXPos() {
        return mMouseXPos;
    }

    // ==================
    // Jem::MouseMovedEvent::GetYPos
    // ==================
    int MouseMovedEvent::GetYPos() {
        return mMouseYPos;
    }


    // ==================
    // Jem::MouseScrolledEvent::MouseScrolledEvent
    // ==================
    MouseScrolledEvent::MouseScrolledEvent(int xOffset, int yOffset) :
        mXOffset(xOffset),
        mYOffset(yOffset) {}

    // ==================
    // Jem::MouseScrolledEvent::GetType
    // ==================
    EventType MouseScrolledEvent::GetType() const {
        return EventType::MouseScrolled;
    }
    // ==================
    // Jem::MouseScrolledEvent::GetXPos
    // ==================
    int MouseScrolledEvent::GetXOffset() {
        return mXOffset;
    }

    // ==================
    // Jem::MouseScrolledEvent::GetYPos
    // ==================
    int MouseScrolledEvent::GetYOffset() {
        return mYOffset;
    }


    // ==================
    // Jem::MouseEvent::MouseEvent
    // ==================
    MouseEvent::MouseEvent(MouseCode mouseCode) :
        mouseCode(mouseCode) {}

    // ==================
    // Jem::MouseEvent::GetMouseCode
    // ==================
    MouseCode MouseEvent::GetMouseCode() const {
        return mouseCode;
    }


    // ==================
    // Jem::MouseButtonPressedEvent::MouseButtonPressedEvent
    // ==================
    MouseButtonPressedEvent::MouseButtonPressedEvent(MouseCode mouseCode) :
        MouseEvent(mouseCode) {}

    // ==================
    // Jem::MouseButtonPressedEvent::GetType
    // ==================
    EventType MouseButtonPressedEvent::GetType() const {
        return EventType::MouseButtonPressed;
    }

    // ==================
    // Jem::MouseButtonReleasedEvent::MouseButtonReleasedEvent
    // ==================
    MouseButtonReleasedEvent::MouseButtonReleasedEvent(MouseCode mouseCode) :
        MouseEvent(mouseCode) {}

    // ==================
    // Jem::MouseButtonReleasedEvent::GetType
    // ==================
    EventType MouseButtonReleasedEvent::GetType() const {
        return EventType::MouseButtonReleased;
    }

}