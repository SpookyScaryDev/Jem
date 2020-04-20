#include "JemPCH.h"
#include "EventDispatcher.h"

namespace Jem {

namespace EventDispatcher {
    std::vector<EventCallback> eventCallbacks;

    void DispatchEvent(Event* e) {
        for (EventCallback callback : eventCallbacks) {
            callback(e);
        }
    }

    void SetEventCallback(EventCallback callback) {
        eventCallbacks.push_back(callback);
    }
}

}