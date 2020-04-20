#pragma once

#include <Core/Event/Event.h>
#include <Core/Input/MouseCodes.h>

namespace Jem {
// ===============================================================================
//
//     Contains the new position of the mouse.
//
// ===============================================================================
class MouseMovedEvent : public Event {
public:
                            MouseMovedEvent(int x, int y);
    virtual EventType    GetType()    const override;
    int                  GetXPos();
    int                  GetYPos();

private:
    int                  mMouseXPos;
    int                  mMouseYPos;
};

// ===============================================================================
//
//     Contains the change in position of the mouse wheel.
//
// ===============================================================================
class MouseScrolledEvent : public Event {
public:
                            MouseScrolledEvent(int xOffset, int yOffset);
    virtual EventType    GetType()    const override;
    int                  GetXOffset();
    int                  GetYOffset();

private:
    int                  mYOffset;
    int                  mXOffset;
};

// ===============================================================================
//
//     Base Mouse Event Class.
//     Contains a mousecode used by both mouse button pressed and released events.
//
// ===============================================================================
class MouseEvent : public Event {
public:
    virtual MouseCode    GetMouseCode() const;
protected:
                            MouseEvent(MouseCode mouseCode);
    MouseCode            mouseCode;
};

// ===============================================================================
//
//     Represents a mouse button press.
//
// ===============================================================================
class MouseButtonPressedEvent : public MouseEvent {
public:
                            MouseButtonPressedEvent(MouseCode mouseCode);
    virtual EventType    GetType()    const override;
};

// ===============================================================================
//
//     Represents a button release.
//
// ===============================================================================
class MouseButtonReleasedEvent : public MouseEvent {
public:
                            MouseButtonReleasedEvent(MouseCode mouseCode);
    virtual EventType    GetType()    const override;
};

}