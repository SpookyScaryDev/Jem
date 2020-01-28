#pragma once

#include <Core/Core.h>

namespace Jem {
	class EntityAdmin;

	// A System which stores behavior to be performed on Components.
	class System {
	public:
		                      System(EntityAdmin* admin);
		virtual               ~System() = default;

		virtual void          Update(/* timeStep */) = 0; // Update system each frame.
		template <typename S>
		static unsigned int   GetIndex();                 // Get Index for placement in ComponentPool

	protected:
		EntityAdmin*          mAdmin;

	private:
		static unsigned int*  GetCount();
	};

	template <typename S>
	inline unsigned int System::GetIndex() {
		// Check is S is Component.
		JEM_CORE_ASSERT((std::is_base_of<System, S>::value), "Cannot GetIndex of a non System type.");

		static unsigned int index = (*GetCount())++;
		return index;
	}
}