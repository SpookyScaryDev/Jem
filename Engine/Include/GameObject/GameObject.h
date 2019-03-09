#pragma once

#include <Core/Core.h>
#include <Utils/StringID.h>
#include <GameObject/Components/Component.h>
#include <GameObject/Components/TransformComponent.h>

namespace Jem {
	
	template <typename T>
	inline void AddComponents(GameObjectID gameObjectID, T component) {
		Application* app = Application::GetApplication();

		if (typeid(T) == typeid(TransformComponent)) {
			component.mID = gameObjectID;
			// Add component to the correct place in the array;
			app->mComponents.TransformComponents[app->mComponents.CurrentTransformComponents] = component;
			++app->mComponents.CurrentTransformComponents;
		}
	}

	template <typename Arg, typename ... Args>
	inline void AddComponents(GameObjectID gameObjectID, Arg first, Args ... args) {
		AddComponents(gameObjectID, first);
		AddComponents(gameObjectID, args...);
	}

	template <typename ... Args>
	inline GameObjectID CreateGameObject(const char* name, Args ... args) {
		GameObjectID id = SID((char*)name);
		AddComponents(id, args...);
		return id;
	}

}