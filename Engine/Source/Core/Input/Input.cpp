#include "JemPCH.h"

#include "Input.h"

#include <SDL.h>
#include <Core/Input/KeyCodes.h>

namespace Jem {
	namespace Input {
		const Uint8* keyboardState;

		void Init() {
			keyboardState = SDL_GetKeyboardState(nullptr);
		}

		void Destroy() {
			delete keyboardState;
		}

		void Update() {
			SDL_Event event;
			while ((SDL_PollEvent(&event)) != 0) // TODO: Sort This Out!
			{
			}
		}

		bool IsKeyPressed(KeyCode key) {
			return keyboardState[key];
		}
	}
}