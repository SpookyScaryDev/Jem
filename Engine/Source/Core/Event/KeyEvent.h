#pragma once

#include <Core/Event/Event.h>
#include <Core/Input/KeyCodes.h>

namespace Jem {

// ===============================================================================
//
//     Base Key Event Class.
//     Contains a keycode used by both key pressed and released events.
//     TODO: Maybe add key repeat count?
//
// ===============================================================================
class KeyEvent : public Event {
public:
    virtual KeyCode      GetKeyCode() const;
protected:
                         KeyEvent(KeyCode keyCode);
    KeyCode              keyCode;
};

// ===============================================================================
//
//     Represents a key press.
//
// ===============================================================================
class KeyPressedEvent : public KeyEvent {
public:
                         KeyPressedEvent(KeyCode keyCode);
    virtual EventType    GetType()    const override;
};

// ===============================================================================
//
//     Represents a key release.
//
// ===============================================================================
class KeyReleasedEvent : public KeyEvent {
public:
                         KeyReleasedEvent(KeyCode keyCode);
    virtual EventType    GetType()    const override;
};

}