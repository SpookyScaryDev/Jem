#pragma once

#include <Jem/Common.h>
#include <Jem/GameObject/Components/Component.h>

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