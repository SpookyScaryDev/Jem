#pragma once

#include <type_traits>

#include <Core/Core.h>
#include <ECS/EntityAdmin.h>
#include <vector>
#include <iterator>

namespace Jem {
	// Iterates through all components of ComponentArg type.
	template <class ComponentArg>
	class JEM_API ComponentIterator {
	public:
		ComponentIterator(EntityAdmin* admin) :
			mComponentVector(admin->GetComponents<ComponentArg>())
		{
			// Check is ComponentArg is Component.
			JEM_CORE_ASSERT((std::is_base_of<Component, ComponentArg>::value), "Cannot get ComponentIterator of a non Component type.");

			mIterator = mComponentVector->begin();
			mEnd      = mComponentVector->end();
		}

		ComponentIterator begin() {
			mIterator = mComponentVector->begin();
			return *this;
		}

		ComponentIterator end() {
			mIterator = mEnd;
			return *this;
		}

		ComponentIterator& operator++() {
			mIterator++;
			return *this;
		}

		bool operator!=(const ComponentIterator& right) const {
			return mIterator != right.mIterator;
		}

		ComponentArg* operator* () {
			return static_cast<ComponentArg*>(*mIterator);
		}

	private:
		std::vector<Component*>*                mComponentVector;
		std::vector<Component*>::const_iterator mIterator;
		std::vector<Component*>::const_iterator mEnd;
	};
}