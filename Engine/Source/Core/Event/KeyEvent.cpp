#include "JemPCH.h"
#include "KeyEvent.h"

#include <Core/Event/Event.h>
#include <Core/Input/KeyCodes.h>

namespace Jem {

// ==================
// Jem::KeyEvent::KeyEvent
// ==================
KeyEvent::KeyEvent(KeyCode keyCode) :
    keyCode(keyCode) {}

// ==================
// Jem::KeyEvent::GetKeyCode
// ==================
KeyCode KeyEvent::GetKeyCode() const {
    return keyCode;
}

// ==================
// Jem::KeyPressedEvent::KeyPressedEvent
// ==================
KeyPressedEvent::KeyPressedEvent(KeyCode keyCode) :
    KeyEvent(keyCode) {}

// ==================
// Jem::KeyPressedEvent::GetType
// ==================
EventType KeyPressedEvent::GetType() const {
    return EventType::KeyPressed;
}

// ==================
// Jem::KeyReleasedEvent::KeyReleasedEvent
// ==================
KeyReleasedEvent::KeyReleasedEvent(KeyCode keyCode) :
    KeyEvent(keyCode) {}

// ==================
// Jem::KeyReleasedEvent::GetType
// ==================
EventType KeyReleasedEvent::GetType() const {
    return EventType::KeyReleased;
}

}