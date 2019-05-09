#pragma once

#include <Core/Core.h>
#include <GameObject/GameObject.h>
#include <GameObject/Component.h>
#include <GameObject/Components.h>
#include <Utils/StringID.h>

namespace Jem {

	// A base app class.
	class JEM_API Application
	{
		template <typename T>
		friend void AddComponents(StringID gameObjectID, T component);

	public:
		                    Application();
		virtual             ~Application();

		static Application* GetApplication();
		void                Run();

	private:
		Components          mComponents;

		static Application* mApplication;
	};
}