#include "JemPCH.h"
#include "ComponentPool.h"

namespace Jem {
	ComponentPool::~ComponentPool() {
		// Clean up components
		for (int i = 0; i < mComponentPools.size(); i++)
			for (Component* component : mComponentPools[i])
				delete component;
	}

	void ComponentPool::RemoveComponent(unsigned int index, Component* component) {
		auto iterator = std::find(mComponentPools[index].begin(), mComponentPools[index].end(), component); // Find Component.
		if (iterator != mComponentPools[index].end())
			mComponentPools[index].erase(iterator);    // Erase component from the correct pool.
	}
}
