#include "JemPCH.h"

#include "Window.h"

#include <SDL.h>


namespace Jem {
	SDL_Window* rawSDLWindow;
	int         windowWidth;
	int         windowHeight;

	void InitWindow(const char* name, int width, int height) {
		windowWidth = width;
		windowHeight = height;

		rawSDLWindow = SDL_CreateWindow(name,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			width,
			height,
			SDL_WINDOW_SHOWN);

		if (rawSDLWindow == nullptr) {
			// The window could not be created.
			JEM_CORE_ERROR("InitWindow: Failed to create window - ", SDL_GetError());
		}
	}

	void DestroyWindow() {
		SDL_DestroyWindow(rawSDLWindow);
	}

	int GetWindowWidth() {
		return windowWidth;
	}

	int GetWindowHeight() {
		return windowHeight;
	}
}