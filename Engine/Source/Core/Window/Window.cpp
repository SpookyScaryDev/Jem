#include "JemPCH.h"

#include "Window.h"

#include <SDL.h>


namespace Jem {
	Window::Window(const char* name, int width, int height) :
		mWidth(width),
		mHeight(height)
	
	{
		mWindow = SDL_CreateWindow(name,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			width,
			height,
			SDL_WINDOW_SHOWN);
	}

	Window::~Window() {
		SDL_DestroyWindow(mWindow);
	}

	int Window::GetWidth() const {
		return mWidth;
	}

	int Window::GetHeight() const {
		return mHeight;
	}
}