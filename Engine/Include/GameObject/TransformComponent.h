#pragma once

#include <Core/Core.h>
#include <GameObject/Component.h>

namespace Jem {

	class JEM_API TransformComponent : public Component
	{
	public:
		                    TransformComponent();
		virtual             ~TransformComponent();	       

		virtual void        Update();

	private:
		//Data...
	};
}