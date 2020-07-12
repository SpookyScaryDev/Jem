#pragma once

#include "Entity.h"
#include "ComponentArray.h"
#include <bitset>
#include <array>
#include <vector>
#include <functional>

namespace Jem {

const int MAX_COMPONENT_TYPES = 32;

using ComponentType      = int;
using ComponentSignature = std::bitset<MAX_COMPONENT_TYPES>;

class ECSManager;

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

template<typename... Args>
std::vector<Entity> ECSManager::GetEntitiesWith() {
    ComponentSignature systemSignature = CreateComponentSignature<Args...>();
    std::vector<Entity> entities;
    for (auto i : mComponentSignatures) {
        if ((i.second & systemSignature) == i.second) entities.push_back(i.first);
    }
    return entities;
}

template<typename T>
T& ECSManager::GetComponent(Entity entity) const {
    return GetComponentArray<T>()->GetComponent(entity);
}

template<typename T>
void ECSManager::RegisterComponentType() {
    if (mComponentArrays[GetComponentType<T>()] == nullptr) {
        mComponentArrays[GetComponentType<T>()] = new ComponentArray<T>();
    }
}

template<typename T>
void ECSManager::AddComponent(Entity entity, T component) {
    if (mComponentArrays[GetComponentType<T>()] != nullptr) {
        GetComponentArray<T>()->AddComponent(entity, component);
        SetComponentSignature(entity, GetComponentSignature(entity).set(GetComponentType<T>(), true));
    }
}

template<typename T>
void ECSManager::RemoveComponent(Entity entity) {
    if (mComponentArrays[GetComponentType<T>()] != nullptr) {
        GetComponentArray<T>()->RemoveComponent(entity);
        SetComponentSignature(entity, GetComponentSignature(entity).set(GetComponentType<T>(), false));
    }
}

template<typename T>
ComponentArray<T>* ECSManager::GetComponentArray() const {
    return ((ComponentArray<T>*) (mComponentArrays[GetComponentType<T>()]));
}

template<typename T>
ComponentType ECSManager::GetComponentType() const {
    static int index = (*GetComponentCount())++;  return index;
}

template<typename T>
ComponentSignature ECSManager::CreateComponentSignature() const {
    ComponentSignature signature;
    signature.set(GetComponentType<T>(), true);
    return signature;
}

template<typename T, typename Second, typename... Args>
ComponentSignature ECSManager::CreateComponentSignature() const {
    ComponentSignature signature;
    signature.set(GetComponentType<T>(), true);
    signature |= CreateComponentSignature<Second, Args...>();
    return signature;
}

}
