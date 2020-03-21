#pragma once

struct SDL_Window;

namespace Jem {

namespace Window {
    void                Init(const char* name, int width, int height);
    void                Destroy();

    int                 GetWidth();
    int                 GetHeight();

    extern SDL_Window*  rawSDLWindow;
}

}