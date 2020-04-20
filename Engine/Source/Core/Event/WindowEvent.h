#pragma once

#include <Core/Event/Event.h>

namespace Jem {

// TODO: Add more, eg. window resize, lost focus etc
class WindowCloseEvent: public Event { 
public:
    virtual EventType    GetType() const;
};

}