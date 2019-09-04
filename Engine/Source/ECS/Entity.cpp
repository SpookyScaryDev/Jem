#include "JemPCH.h"
#include "Entity.h"

#include <ECS/EntityAdmin.h>
#include <ECS/ComponentPool.h>

namespace Jem {
	Entity::Entity(StringID id, ComponentPool* componentPool) :
		mID(id),
		mComponentPool(componentPool) {}

	Entity::~Entity() {
		DestroyAllComponents();
	}

	StringID Entity::GetStringID() {
		return mID;
	}

	void Entity::AddComponent(unsigned int index, Component* component) {
		// Adds Component to Entities list of Component pointers.
		mComponents[index] = component;
	}

	void Entity::DestroyAllComponents() {
		for (const auto& component : mComponents)
			// Removes all Components attached to the Entity from the pool.
			mComponentPool->RemoveComponent(component.first, component.second);

		mComponents.clear();
	}
}