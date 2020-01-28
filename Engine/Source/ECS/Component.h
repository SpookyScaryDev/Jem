#pragma once

#include <type_traits>

#include <Core/Core.h>

namespace Jem {
	// Base Component class: stores data and accessors for Entities.
	class Component {
	public:
		                      Component()  = default;
		virtual               ~Component() = default;

		template <typename C>
		static unsigned int   GetIndex();            // Get Index for placement in ComponentPool

	private:
		static unsigned int*  GetCount();
	};

	template <typename C>
	inline unsigned int Component::GetIndex() {
		// Check is C is Component.
		JEM_CORE_ASSERT((std::is_base_of<Component, C>::value), "Cannot GetIndex of a non Component type.");

		static unsigned int index = (*GetCount())++;
		return index;
	}
}

