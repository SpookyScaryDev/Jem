#include <Jem.h>

using namespace Jem;

class Sandbox : public Game {
public:
    Sandbox() : Game("Sandbox", 500, 500) {
        texture = new Texture("Assets/NotArt.bmp");

        position.x = Window::GetWidth() / 2;
        position.y = Window::GetHeight() / 2;

        Renderer::SetClearColour(Vector4d(100, 100, 255, 255));
    }

    void Update(double deltaTime) {
        if (Input::IsKeyPressed(KeyCode::KEY_UP))     position.y -= 5;
        if (Input::IsKeyPressed(KeyCode::KEY_DOWN))   position.y += 5;
        if (Input::IsKeyPressed(KeyCode::KEY_LEFT))   position.x -= 5;
        if (Input::IsKeyPressed(KeyCode::KEY_RIGHT))  position.x += 5;
        if (Input::IsKeyPressed(KeyCode::KEY_ESCAPE)) mIsRunning = false;

        Renderer::Clear();
        Renderer::DrawFilledRectangle(position, Vector2d(100, 100), Vector4d(255, 100, 100, 255));
        Renderer::DrawRectangle(position, Vector2d(100, 100), Vector4d(10, 255, 100, 255));
        Renderer::DrawTexturedRectangle(position + Vector2d(15, 15), Vector2d(70, 70), *texture);

        Renderer::DrawLine(Vector2d(position.x, position.y + 75), Vector2d(position.x - 25, position.y + 50), Vector4d(255, 100, 100, 255));
        Renderer::DrawLine(Vector2d(position.x + 100, position.y + 75), Vector2d(position.x + 125, position.y + 50), Vector4d(255, 100, 100, 255));
    }

private:
    Vector2d position;
    Texture* texture;
};

namespace Jem {
    Game* CreateGame() {
        return new Sandbox();
    }
}
