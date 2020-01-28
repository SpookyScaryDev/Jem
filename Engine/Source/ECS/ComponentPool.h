#pragma once

#include <type_traits>

#include <Core/Core.h>
#include <ECS/Component.h>
#include <vector>

namespace Jem {
	// A data structure to store Component objects.
	// A vector is created for each Component type. These vectors are stored in another vector indexed through
	// Component::GetIndex.
	class ComponentPool {
	public:
		                                      ComponentPool()  = default;
		                                      ~ComponentPool();

		template<class C, typename ...Args>
		Component*                            CreateComponent(Args ...args);   // Creates a Component and stores it in the pool.
		template<class C>
		std::vector<Component*>*              GetComponents();                 // Gets all components of type C.
		void                                  RemoveComponent(unsigned int index, Component* component); // Remove Component from correct pool.

	private:
		std::vector<std::vector<Component*>>  mComponentPools;
	};

	template<class C, typename ...Args>
	inline Component* ComponentPool::CreateComponent(Args... args) {
		// Check is C is Component.
		JEM_CORE_ASSERT((std::is_base_of<Component, C>::value), "Cannot create Components of a non Component type.");

		if (Component::GetIndex<C>() >= mComponentPools.size()) { // Make sure pool exists.
			mComponentPools.resize(Component::GetIndex<C>() + 1);
		}

		Component* component = new C(args...);
		mComponentPools[Component::GetIndex<C>()].push_back(component);

		return component;
	}

	template<class C>
	inline std::vector<Component*>* ComponentPool::GetComponents() {
		// Check is C is Component.
		JEM_CORE_ASSERT((std::is_base_of<Component, C>::value), "Cannot get Components of a non Component type.");

		return &mComponentPools[Component::GetIndex<C>()];
	}
}