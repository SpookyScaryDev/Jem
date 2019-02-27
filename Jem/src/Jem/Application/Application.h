#pragma once

#include <Jem/Common.h>
#include <Jem/GameObject/GameObject.h>
#include <Jem/GameObject/Components/Component.h>
#include <Jem/GameObject/Components/Components.h>
#include <Jem/utils/StringID.h>

namespace Jem {

	// A base app class.
	class JEM_API Application
	{
		template <typename T>
		friend void AddComponents(GameObjectID gameObjectID, T component);

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