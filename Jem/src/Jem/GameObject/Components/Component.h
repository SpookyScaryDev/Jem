#pragma once

#include <Jem/Common.h>
#include <Jem/utils/StringID.h>

namespace Jem {

	// A base component class for use by GameObjects.
	class JEM_API Component
	{
	public:
		static const int    MAX_COMPONENTS = 10;

		                    Component();
		virtual             ~Component() {};

		virtual void        Update() = 0;

		GameObjectID        mID;
	};
}