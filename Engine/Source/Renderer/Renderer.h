#pragma once

namespace Jem {

namespace Renderer {
    void                    Init();
    void                    Shutdown();

    void                    SetClearColour(int r, int g, int b);
    void                    Clear();                             // Clear screen to the clear colour.
    void                    Refresh();
}

}