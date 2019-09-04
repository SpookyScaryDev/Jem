#include "JemPCH.h"
#include "EntityAdmin.h"

#include <ECS/Entity.h>
#include <ECS/Component.h>
#include <ECS/System.h>
#include <vector>

namespace Jem {
	EntityAdmin::~EntityAdmin() {
		// Clean up systems.
		for (System* system : mSystems)
			delete system;

		// Clean up entities
		for (Entity* entity : mEntities)
			delete entity;
	}

	void EntityAdmin::Update(/* timeStep */) {
		for (System* system : mSystems)
			system->Update(/* timeStep */);
	}

	Entity* EntityAdmin::CreateEntity(const char* name) {
		// TODO: Need a place to store entities.
		Entity* entity = new Entity(SID(name), &mComponentPool);
		mEntities.push_back(entity);

		return entity;
	}

	Entity* EntityAdmin::GetEntity(const char* name) {
		StringID id = SID(name);
		for (Entity* entity : mEntities)
			if (entity->GetStringID().GetID() == id.GetID()) // Compare hashed StringIDs
				return entity;
	}

	void EntityAdmin::DestroyEntity(const char* name) {
		StringID id = SID(name);
		for (int i = 0; i <= mEntities.size(); i++) {
			if (mEntities[i]->GetStringID().GetID() == id.GetID()) { // Compare hashed StringIDs
				delete mEntities[i];
				mEntities.erase(mEntities.begin() + i);
			}
		}
	}
}
