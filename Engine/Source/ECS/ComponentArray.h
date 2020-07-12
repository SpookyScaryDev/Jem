#pragma once

#include "Entity.h"
#include <unordered_map>

namespace Jem {

class ComponentArrayAbstract {
public:
    virtual void                    OnEntityDestroyed(Entity entity) = 0;
};

template<typename T>
class ComponentArray : public ComponentArrayAbstract {
public:
    void                            AddComponent(Entity entity, T component);
    void                            RemoveComponent(Entity enitity);

    T&                              GetComponent(Entity entity);

    virtual void                    OnEntityDestroyed(Entity entity) override;

private:
    std::unordered_map<Entity, T>   mComponents;
};

template<typename T>
void ComponentArray<T>::AddComponent(Entity entity, T component) {
    mComponents.emplace(entity, component);
}

template<typename T>
void ComponentArray<T>::RemoveComponent(Entity entity) {
    mComponents.erase(entity);
}

template<typename T>
T& ComponentArray<T>::GetComponent(Entity enitity) {
    return mComponents[enitity];
}

template<typename T>
void ComponentArray<T>::OnEntityDestroyed(Entity entity) {
    for (auto component : mComponents) {
        if (component.first == entity) {
            mComponents.erase(entity);
            return;
        }
    }
}

}