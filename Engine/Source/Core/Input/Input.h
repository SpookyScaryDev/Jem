#pragma once

#include <Core/Input/KeyCodes.h>

namespace Jem {
	namespace Input {
		void                    Init();
		void                    Destroy();

		void                    Update();
		
		bool                    IsKeyPressed(KeyCode key);
	}
}