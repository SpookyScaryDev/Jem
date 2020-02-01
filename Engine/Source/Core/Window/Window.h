#pragma once

struct SDL_Window;

namespace Jem {
	void                InitWindow(const char* name, int width, int height);
	void                DestroyWindow();

	int                 GetWindowWidth();
	int                 GetWindowHeight();

	extern SDL_Window*  rawSDLWindow; // TODO: Getter?
}