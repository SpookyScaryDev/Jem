#pragma once

namespace Jem {
	void                InitWindow(const char* name, int width, int height);
	void                DestroyWindow();

	int                 GetWindowWidth();
	int                 GetWindowHeight();
}