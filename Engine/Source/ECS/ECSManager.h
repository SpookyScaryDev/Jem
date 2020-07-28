#pragma once

#include "Entity.h"
#include "ComponentArray.h"
#include <bitset>
#include <array>
#include <vector>
#include <functional>

namespace Jem {

const int MAX_COMPONENT_TYPES = 32;

// ===============================================================================
//
//     ComponentType is an index into a vector of ComponentArrays.
//     A component ID is 'assigned' when a component type is registered.
//
// ===============================================================================
using ComponentType      = int;

// ===============================================================================
//
//     ComponentSignature is a bitset where a bit at the index of a component type
//     indicates if that component type is associated with a signature.
//
// ===============================================================================
using ComponentSignature = std::bitset<MAX_COMPONENT_TYPES>;

// ===============================================================================
//
//     ECSManager is used to manage ComponentArrays and assign components to
//     entities.
//
// ===============================================================================
class ECSManager {
public:
                              ECSManager();
                              ~ECSManager();

                              ECSManager(const ECSManager& other)            = delete;
                              ECSManager(ECSManager&& other)                 = delete;
                              ECSManager& operator=(const ECSManager& other) = delete;
                              ECSManager& operator=(ECSManager&& other)      = delete;

    // Entity Functions
    Entity                    CreateEntity(int id); // TODO: use hashed string ids instead.
    void                      DestroyEntity(Entity entity);
    template<typename... Args>
    std::vector<Entity>       GetEntitiesWith();
    template<typename T>
    T&                        GetComponent(Entity entity) const;

    // Component Functions
    template<typename T>
    void                      RegisterComponentType();
    template<typename T>
    void                      AddComponent(Entity entity, T component);
    template<typename T>
    void                      RemoveComponent(Entity entity);

private:
    ComponentSignature        GetComponentSignature(Entity entity) const;
    void                      SetComponentSignature(Entity entity, ComponentSignature signature);
    template<typename T>
    ComponentArray<T>*        GetComponentArray() const;
    template<typename T>
    ComponentType             GetComponentType()  const;
    int*                      GetComponentCount() const;
    template<typename T>
    ComponentSignature        CreateComponentSignature() const;
    template<typename T, typename Second, typename... Args>
    ComponentSignature        CreateComponentSignature() const;

    std::unordered_map<Entity, ComponentSignature>           mComponentSignatures;
    std::array<ComponentArrayAbstract*, MAX_COMPONENT_TYPES> mComponentArrays;
};

// ==================
// Jem::ECSManager::GetEntitiesWith
// ==================
template<typename... Args>
std::vector<Entity> ECSManager::GetEntitiesWith() {
    ComponentSignature systemSignature = CreateComponentSignature<Args...>();
    std::vector<Entity> entities;
    for (auto i : mComponentSignatures) {
        if ((i.second & systemSignature) == systemSignature) 
            entities.push_back(i.first);
    }
    return entities;
}

// ==================
// Jem::ECSManager::GetComponent
// ==================
template<typename T>
T& ECSManager::GetComponent(Entity entity) const {
    return GetComponentArray<T>()->GetComponent(entity);
}

// ==================
// Jem::ECSManager::RegisterComponentType
// ==================
template<typename T>
void ECSManager::RegisterComponentType() {
    if (mComponentArrays[GetComponentType<T>()] == nullptr) {
        mComponentArrays[GetComponentType<T>()] = new ComponentArray<T>();
    }
}

// ==================
// Jem::ECSManager::AddComponent
// ==================
template<typename T>
void ECSManager::AddComponent(Entity entity, T component) {
    if (mComponentArrays[GetComponentType<T>()] != nullptr) {
        GetComponentArray<T>()->AddComponent(entity, component);
        SetComponentSignature(entity, GetComponentSignature(entity).set(GetComponentType<T>(), true));
    }
}

// ==================
// Jem::ECSManager::RemoveComponent
// ==================
template<typename T>
void ECSManager::RemoveComponent(Entity entity) {
    if (mComponentArrays[GetComponentType<T>()] != nullptr) {
        GetComponentArray<T>()->RemoveComponent(entity);
        SetComponentSignature(entity, GetComponentSignature(entity).set(GetComponentType<T>(), false));
    }
}

// ==================
// Jem::ECSManager::GetComponentArray
// ==================
template<typename T>
ComponentArray<T>* ECSManager::GetComponentArray() const {
    return ((ComponentArray<T>*) (mComponentArrays[GetComponentType<T>()]));
}

// ==================
// Jem::ECSManager::GetComponentType
// ==================
template<typename T>
ComponentType ECSManager::GetComponentType() const {
    static int index = (*GetComponentCount())++;  return index;
}

// ==================
// Jem::ECSManager::CreateComponentSignature
// ==================
template<typename T>
ComponentSignature ECSManager::CreateComponentSignature() const {
    ComponentSignature signature;
    signature.set(GetComponentType<T>(), true);
    return signature;
}

// ==================
// Jem::ECSManager::CreateComponentSignature
// ==================
template<typename T, typename Second, typename... Args>
ComponentSignature ECSManager::CreateComponentSignature() const {
    ComponentSignature signature;
    signature.set(GetComponentType<T>(), true);
    signature |= CreateComponentSignature<Second, Args...>();
    return signature;
}

}
