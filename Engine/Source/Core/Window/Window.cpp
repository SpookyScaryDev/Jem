#include "JemPCH.h"

#include "Window.h"

#include <SDL.h>


namespace Jem {
	SDL_Window* window;
	int         windowWidth;
	int         windowHeight;

	void InitWindow(const char* name, int width, int height) {
		windowWidth = width;
		windowHeight = height;

		window = SDL_CreateWindow(name,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			width,
			height,
			SDL_WINDOW_SHOWN);
	}

	void DestroyWindow() {
		SDL_DestroyWindow(window);
	}

	int GetWindowWidth() {
		return windowWidth;
	}

	int GetWindowHeight() {
		return windowHeight;
	}
}