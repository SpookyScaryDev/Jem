#include "JemPCH.h"
#include "TextEvent.h"

namespace Jem {


// ==================
// Jem::TextInputEvent::TextInputEvent
// ==================
TextInputEvent::TextInputEvent(const char* text) :
    mText(text) {}

// ==================
// Jem::TextInputEvent::GetType
// ==================
EventType TextInputEvent::GetType() const {
    return EventType::TextInput;
}

// ==================
// Jem::TextInputEvent::GetText
// ==================
const char* TextInputEvent::GetText() const {
    return mText;
}

}