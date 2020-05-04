#include <Jem.h>

using namespace Jem;

class Sandbox : public Game {
public:
    Sandbox() : Game("Sandbox", 500, 500) {
        mousePos = Input::GetMousePosition();
    }

    void OnEvent(Event* event) {
        Game::OnEvent(event);

        switch (event->GetType()) {
            case EventType::WindowClose:
                JEM_MESSAGE("Window closed event");
                break;

            case EventType::KeyPressed:
                JEM_MESSAGE("Key pressed event ", (int)((KeyPressedEvent*)event)->GetKeyCode());
                break;

            case EventType::KeyReleased:
                JEM_MESSAGE("Key released event ", (int)((KeyReleasedEvent*)event)->GetKeyCode());
                break;

            case EventType::MouseMoved:
                JEM_MESSAGE("Mouse moved event ", ((MouseMovedEvent*)event)->GetXPos(), " ", ((MouseMovedEvent*)event)->GetYPos());
                break;

            case EventType::MouseScrolled:
                JEM_MESSAGE("Mouse scrolled event ", ((MouseScrolledEvent*)event)->GetXOffset(), " ", ((MouseScrolledEvent*)event)->GetYOffset());
                break;

            case EventType::MouseButtonPressed:
                JEM_MESSAGE("Mouse button pressed event ", (int)((MouseButtonPressedEvent*)event)->GetMouseCode());
                break;

            case EventType::MouseButtonReleased:
                JEM_MESSAGE("Mouse button released event ", (int)((MouseButtonReleasedEvent*)event)->GetMouseCode());
                break;
        }
    }

    void Update(double deltaTime) {
        static int i = 0;
        double range = 500;

        // Colour shift demo.
        if (i >= range) i = 0;
        i += int(((double(1) + 100.0f) * deltaTime));

        //we want to normalize ratio so that it fits in to 6 regions
        //where each region is 256 units long
        int normalized = int(i / range * 256 * 6);

        //find the distance to the start of the closest region
        int x = normalized % 256;

        int red = 0, grn = 0, blu = 0;
        switch (normalized / 256)
        {
        case 0: red = 255;      grn = x;        blu = 0;       break;//red
        case 1: red = 255 - x;  grn = 255;      blu = 0;       break;//yellow
        case 2: red = 0;        grn = 255;      blu = x;       break;//green
        case 3: red = 0;        grn = 255 - x;  blu = 255;     break;//cyan
        case 4: red = x;        grn = 0;        blu = 255;     break;//blue
        case 5: red = 255;      grn = 0;        blu = 255 - x; break;//magenta
        }
        Renderer::SetClearColour(red, grn, blu);
    }
};

namespace Jem {
    Game* CreateGame() {
        return new Sandbox();
    }
}