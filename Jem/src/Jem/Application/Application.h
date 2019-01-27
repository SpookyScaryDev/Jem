#pragma once

#include <Jem/Common.h>

namespace Jem {

	class JEM_API Application
	{

	public:
		                    Application();
		virtual             ~Application();

		void                run();

	};
}