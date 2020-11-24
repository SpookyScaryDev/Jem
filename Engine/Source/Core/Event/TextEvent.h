#pragma once

#include <Core/Event/Event.h>
#include <Core/Input/KeyCodes.h>

namespace Jem {


// ===============================================================================
//
//     Created when text is inputed, triggered by SDL_StartTextInput.
//     Contains the text entered since the last text input event.
//     TODO: Make a new function to trigger text input events.
//
// ===============================================================================
class TextInputEvent : public Event {
public:
                         TextInputEvent(const char* text);

    virtual EventType    GetType() const;
    const char*          GetText() const;

private:
    const char*          mText;
};

}