#pragma once

#include <type_traits>

#include <ECS/Entity.h>
#include <ECS/Component.h>
#include <ECS/System.h>
#include <vector>

namespace Jem {
	// Maintains all Entities, Components and systems.
	class EntityAdmin {
	public:
		                         EntityAdmin()  = default;
		                         ~EntityAdmin();

		void                     Update(/* timeStep */);

		Entity*                  CreateEntity(const char* name);  // Create Entity and add it to the EntityAdmin.
		Entity*                  GetEntity(const char* name);     // Find Entity by StringID.
		void                     DestroyEntity(const char* name); // Destroy Entity by StringID.
		template<class S> 
		System*                  CreateSystem();                  // Create System and add it to the EntityAdmin.
		template<class S>
		void                     RemoveSystem();
		template<class S>
		bool                     HasSystem() const;               // Check if EntityAdmin has System S.

		template<class C>
		std::vector<Component*>* GetComponents();

	private:
		std::vector<Entity*>     mEntities;
		ComponentPool            mComponentPool;
		std::vector<System*>     mSystems;
	};

	template<class S>
	inline System* EntityAdmin::CreateSystem() {
		// Check is S is System.
		JEM_CORE_ASSERT((std::is_base_of<System, S>::value), "Cannot create a System of a non System type.");

		if (HasSystem<S>()) {                            // See if EntityAdmin already has this System.
			JEM_CORE_ERROR("System already exists");
		}

		if (System::GetIndex<S>() >= mSystems.size()) {  // Make sure vector is big enough.
			mSystems.resize(System::GetIndex<S>() + 1, nullptr);
		}

		System* system = new S(this);                   // Add System to vector.
		mSystems[System::GetIndex<S>()] = system;

		return system;
	}

	template<class S>
	inline void EntityAdmin::RemoveSystem() {
		// Check is S is System.
		JEM_CORE_ASSERT((std::is_base_of<System, S>::value), "EntityAdmin cannot have Systems of a non System type.");

		delete mSystems[System::GetIndex<S>()];
		mSystems[System::GetIndex<S>()] = nullptr;
		mSystems.erase(mSystems.begin() + System::GetIndex<S>());
	}

	template<class S>
	inline bool EntityAdmin::HasSystem() const {
		// Check is S is System.
		JEM_CORE_ASSERT((std::is_base_of<System, S>::value), "EntityAdmin cannot have Systems of a non System type.");

		return mSystems.size() > System::GetIndex<S>() && mSystems[System::GetIndex<S>()] != nullptr;
	}

	template<class C>
	inline std::vector<Component*>* EntityAdmin::GetComponents() {
		// Check is C is Component.
		JEM_CORE_ASSERT((std::is_base_of<Component, C>::value), "Cannot get Components of a non Component type.");

		return mComponentPool.GetComponents<C>();
	}
}