#pragma once

#include <Core/Core.h>

struct SDL_Window;

namespace Jem {
	class JEM_API Window {
	public:
		                    Window(const char* name, int width, int height);
		                    ~Window();

		int                 GetWidth()  const;
		int                 GetHeight() const;

	private:
		SDL_Window*         mWindow;
		int                 mWidth;
		int                 mHeight;
	};
}