#include "JemPCH.h"

#include "Input.h"

#include <SDL.h>

#include <Core/Input/KeyCodes.h>
#include <Core/Input/MouseCodes.h>

namespace Jem {
	namespace Input {
		const Uint8* keyboardState;
		Uint8        mouseState;

		int mouseXPosition; // TODO: Replace with a vector maybe.
		int mouseYPosition;

		void Init() {
			keyboardState = SDL_GetKeyboardState(nullptr);
		}

		void Destroy() {}

		bool Update() {
			SDL_Event event;
			while ((SDL_PollEvent(&event)) != 0) { // TODO: Add mouse scrolling maybe.
				if (event.type == SDL_QUIT) {
					return false;
				}
			}
			mouseState = SDL_GetMouseState(&mouseXPosition, &mouseYPosition);

			return true;
		}

		bool IsKeyPressed(KeyCode key) {
			return keyboardState[static_cast<Uint8>(key)];
		}

		bool IsMouseButtonPressed(MouseCode button) {
			return mouseState & SDL_BUTTON(static_cast<int>(button));
		}

		std::pair<int, int> GetMousePosition() {
			return std::make_pair(mouseXPosition, mouseYPosition);
		}
	}
}