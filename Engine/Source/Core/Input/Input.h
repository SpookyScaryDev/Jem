#pragma once

#include <Core/Input/KeyCodes.h>
#include <Core/Input/MouseCodes.h>

namespace Jem {
	namespace Input {
		void                    Init();
		void                    Destroy();

		bool                    Update(); // Returns true to continue, false to stop.
		                                  // TODO: Try not to do this!
		
		bool                    IsKeyPressed(KeyCode key);
		bool                    IsMouseButtonPressed(MouseCode key);
		std::pair<int, int>     GetMousePosition(); // TODO: Replace with vector maybe.
	}
}