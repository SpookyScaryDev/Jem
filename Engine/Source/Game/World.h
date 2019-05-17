#pragma once

#include <Core/Core.h>
#include <Component/Component.h>
#include <Component/TransformComponent.h>
#include <Utils/StringID.h>

namespace Jem {
	// A game world class responsible for managing components.
	class JEM_API World {
	public:
		World() {}
		~World() {}

		template <typename Arg, typename ... Args>
		inline void AddComponents(StringID gameObjectID, Arg first, Args ... args) {
			if constexpr (std::is_same_v<Arg, TransformComponent>) {
				first.mID = gameObjectID;
				// Add component to the correct place in the array;
				TransformComponents[CurrentTransformComponents] = first;
				++CurrentTransformComponents;
			} else {
				JEM_CORE_ERROR("You cannot add a component of a non-Jem type");
			}
			if constexpr (sizeof...(args))
				AddComponents(gameObjectID, args...);
		}

		template <typename ... Args>
		inline StringID CreateGameObject(const char* name, Args ... args) {
			StringID id = SID((char*)name);
			AddComponents(id, args...);
			return id;
		}

	private:
		int CurrentTransformComponents = 0;
		TransformComponent* TransformComponents = new TransformComponent[Component::MAX_COMPONENTS];
	};
}

