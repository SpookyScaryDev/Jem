#pragma once

#include "Entity.h"
#include <unordered_map>

namespace Jem {

// ===============================================================================
//
//     Base Component Array.
//     Provides a polymorphic OnEntityDestroyed function so that component arrays
//     for different component types can be cleaned up easily.
//
// ===============================================================================
class ComponentArrayAbstract {
public:
    virtual void                    OnEntityDestroyed(Entity entity) = 0;
};

// ===============================================================================
//
//     A new component array is instantiated for each new component type by the
//     ECSManager.
//
// ===============================================================================
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

// ==================
// Jem::ComponentArray::AddComponent
// ==================
template<typename T>
void ComponentArray<T>::AddComponent(Entity entity, T component) {
    mComponents.emplace(entity, component);
}

// ==================
// Jem::ComponentArray::RemoveComponent
// ==================
template<typename T>
void ComponentArray<T>::RemoveComponent(Entity entity) {
    mComponents.erase(entity);
}

// ==================
// Jem::ComponentArray::GetComponent
// ==================
template<typename T>
T& ComponentArray<T>::GetComponent(Entity enitity) {
    return mComponents[enitity];
}

// ==================
// Jem::ComponentArray::OnEntityDestroyed
// ==================
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