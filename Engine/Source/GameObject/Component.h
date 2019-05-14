#pragma once

#include <Core/Core.h>
#include <Utils/StringID.h>

namespace Jem {
	// A base component class.
	class JEM_API Component {
	public:
		static const int    MAX_COMPONENTS = 10;

		                    Component();
		virtual             ~Component() {};

		virtual void        Update() = 0;

		StringID            mID;
	};
}