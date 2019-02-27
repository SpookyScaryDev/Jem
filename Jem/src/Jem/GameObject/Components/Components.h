#pragma once

#include <Jem/Common.h>
#include <Jem/GameObject/Components/TransformComponent.h>

namespace Jem {

	// A collection of the GameObjects components.
	struct JEM_API Components
	{
		int CurrentTransformComponents = 0;
		TransformComponent* TransformComponents = new TransformComponent[Component::MAX_COMPONENTS];
	};
}