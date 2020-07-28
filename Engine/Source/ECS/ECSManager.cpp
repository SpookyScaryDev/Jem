#include "JemPCH.h"
#include "ECSManager.h"

#include "ComponentArray.h"
#include <unordered_map>
#include <array>
#include <vector>
#include <functional>

namespace Jem {

// ==================
// Jem::ECSManager::ECSManager
// ==================
ECSManager::ECSManager() {
    mComponentSignatures = std::unordered_map<Entity, ComponentSignature>();
    mComponentArrays = std::array<ComponentArrayAbstract*, MAX_COMPONENT_TYPES>();
}

// ==================
// Jem::ECSManager::~ECSManager
// ==================
ECSManager::~ECSManager() {
    for (ComponentArrayAbstract* componentArray : mComponentArrays) {
        if (componentArray != nullptr) {
            delete componentArray;
        }
    }
}

// ==================
// Jem::ECSManager::CreateEntity
// ==================
Entity ECSManager::CreateEntity(int id) {
    mComponentSignatures.emplace(id, ComponentSignature());
    return id;
}

// ==================
// Jem::ECSManager::DestroyEntity
// ==================
void ECSManager::DestroyEntity(Entity entity) {
    for (int i = 0; i < *GetComponentCount(); i++) {
        mComponentArrays[i]->OnEntityDestroyed(entity);
    }
    mComponentSignatures.erase(entity);
}

// ==================
// Jem::ECSManager::GetComponentSignature
// ==================
ComponentSignature ECSManager::GetComponentSignature(Entity entity) const {
    return mComponentSignatures.at(entity);
}

// ==================
// Jem::ECSManager::SetComponentSignature
// ==================
void ECSManager::SetComponentSignature(Entity entity, ComponentSignature signature) {
    mComponentSignatures[entity] = signature;
}

// ==================
// Jem::ECSManager::GetComponentCount
// ==================
int* ECSManager::GetComponentCount() const {
    static int componentCount = 0;
    return &componentCount;
}

}