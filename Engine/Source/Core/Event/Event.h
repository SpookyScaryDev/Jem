#pragma once

namespace Jem {

// ===============================================================================
//
//     Event type marker.
//
// ===============================================================================
enum class EventType {
    WindowClose,
    KeyPressed,  KeyReleased,
    MouseMoved,  MouseScrolled, MouseButtonPressed, MouseButtonReleased,
    TextInput
};

// ===============================================================================
//
//     Base Event Class.
//     To be subclassed by all other event types. Events are currently blocking.
//     TODO: Maybe have one Event class with a string id, instead of inheritance.
//
// ===============================================================================
class Event {
public:
    virtual EventType    GetType() const = 0;
};

}