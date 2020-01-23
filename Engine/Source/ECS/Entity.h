#pragma once

#include <type_traits>

#include <Core/Core.h>
#include <Core/StringID/StringID.h>
#include <ECS/Component.h>
#include <ECS/ComponentPool.h>
#include <map>

namespace Jem {
	// An Entity interface which stores pointers to its components.
	class JEM_API Entity {
	public:
		                         Entity(StringID id, ComponentPool* componentPool);
		virtual                  ~Entity();

		template<class C, typename ... Args>
		void                     Add(Args ... args);                 // Add Component to ComponentPool.
		template<class C>
		void                     Remove();                           // Remove Component from ComponentPool.
		StringID                 GetStringID();

	private:
		void                     AddComponent(unsigned int index, Component* component); // Add Component to vector of Component pointers.
		void                     DestroyAllComponents();             // Removes all Components attached to the Entity from the pool.

		ComponentPool*           mComponentPool;
		StringID                 mID;
		std::map<unsigned int, Component*>      mComponents;         // Stores pointers to components and their type index.
	};

	template<class C, typename ...Args>
	inline void Entity::Add(Args ...args) {
		// Check is C is Component.
		JEM_CORE_ASSERT((std::is_base_of<Component, C>::value), "Cannot add Components of a non Component type.");

		AddComponent(Component::GetIndex<C>(), mComponentPool->CreateComponent<C>(args...)); // Add Component to pool and vector.
	}

	template<class C>
	inline void Entity::Remove() {
		// Check is C is Component.
		JEM_CORE_ASSERT((std::is_base_of<Component, C>::value), "Cannot add Components of a non Component type.");

		AddComponent(Component::GetIndex<C>(), mComponentPool->CreateComponent<C>(args...)); // Add Component to pool and vector.
	}
}
