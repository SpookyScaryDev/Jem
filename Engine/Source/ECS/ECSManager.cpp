#include "JemPCH.h"
#include "ECSManager.h"

#include "ComponentArray.h"
#include <unordered_map>
#include <array>
#include <vector>
#include <functional>

namespace Jem {

ECSManager::ECSManager() {
    mComponentSignatures = std::unordered_map<Entity, ComponentSignature>();
    mComponentArrays = std::array<ComponentArrayAbstract*, MAX_COMPONENT_TYPES>();
}

ECSManager::~ECSManager() {
    for (ComponentArrayAbstract* componentArray : mComponentArrays) {
        if (componentArray != nullptr) {
            delete componentArray;
        }
    }
}

Entity ECSManager::CreateEntity(int id) {
    mComponentSignatures.emplace(id, ComponentSignature());
    return id;
}

void ECSManager::DestroyEntity(Entity entity) {
    for (int i = 0; i < *GetComponentCount(); i++) {
        mComponentArrays[i]->OnEntityDestroyed(entity);
    }
    mComponentSignatures.erase(entity);
}

ComponentSignature ECSManager::GetComponentSignature(Entity entity) const {
    return mComponentSignatures.at(entity);
}

void ECSManager::SetComponentSignature(Entity entity, ComponentSignature signature) {
    mComponentSignatures[entity] = signature;
}

int* ECSManager::GetComponentCount() const {
    static int componentCount = 0;
    return &componentCount;
}

}