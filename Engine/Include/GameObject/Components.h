#pragma once

#include <Core/Core.h>
#include <GameObject/TransformComponent.h>

namespace Jem {

	// A collection of the GameObjects components.
	struct JEM_API Components
	{
		int CurrentTransformComponents = 0;
		TransformComponent* TransformComponents = new TransformComponent[Component::MAX_COMPONENTS];
	};
}