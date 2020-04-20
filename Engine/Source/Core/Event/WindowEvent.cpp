#include "JemPCH.h"
#include "WindowEvent.h"

namespace Jem {

// ==================
// Jem::WindowCloseEvent::GetType
// ==================
EventType WindowCloseEvent::GetType() const {
    return EventType::WindowClose;
}

}