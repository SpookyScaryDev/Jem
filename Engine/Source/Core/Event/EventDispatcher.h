#pragma once

#include <Core/Event/Event.h>
#include <functional>

namespace Jem {

typedef std::function<void(Event*)> EventCallback;

namespace EventDispatcher {
    void            DispatchEvent(Event* e);
    void            SetEventCallback(EventCallback callback);

    template<class Type>
    void SetEventCallbackMethod(Type* instance, void (Type:: *callback)(Event*)) {
        EventCallback boundFunction = std::bind(callback, instance, std::placeholders::_1);
        SetEventCallback(boundFunction);
    }
};

}