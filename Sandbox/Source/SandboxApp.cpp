#include <Jem.h>

using namespace Jem;

struct SubTexture {
    Texture*        texture;
    Vector2d        topLeft;
    Vector2d        bottomRight;
};

SubTexture* CreateSubTextureFromCoords(Texture* texture, const Vector2d& coords, const Vector2d& subTextureSize) {
    Vector2d topLeft = { (coords.x * subTextureSize.x) / texture->GetWidth(), (coords.y * subTextureSize.y) / texture->GetHeight() };
    Vector2d bottomRight = { ((coords.x + 1) * subTextureSize.x) / texture->GetWidth(), ((coords.y + 1) * subTextureSize.y) / texture->GetHeight() };

    return new SubTexture { texture, topLeft, bottomRight };
}

class Sandbox : public Game {
public:
    Sandbox() : Game("Sandbox", 500, 500) {
        texture = new Texture("Assets/foo.bmp");

        frames[0] = CreateSubTextureFromCoords(texture, { 0, 0 }, { 64, 205 });
        frames[1] = CreateSubTextureFromCoords(texture, { 1, 0 }, { 64, 205 });
        frames[2] = CreateSubTextureFromCoords(texture, { 2, 0 }, { 64, 205 });
        frames[3] = CreateSubTextureFromCoords(texture, { 3, 0 }, { 64, 205 });

        position.x = Window::GetWidth() / 2;
        position.y = Window::GetHeight() / 2;

        Renderer::SetClearColour(Vector4d(255, 255, 255, 255));
    }

    void Update(double deltaTime) {
        numFrames++;

        if (Input::IsKeyPressed(KeyCode::KEY_UP))     position.y -= 3;
        if (Input::IsKeyPressed(KeyCode::KEY_DOWN))   position.y += 3;
        if (Input::IsKeyPressed(KeyCode::KEY_LEFT))   position.x -= 3;
        if (Input::IsKeyPressed(KeyCode::KEY_RIGHT))  position.x += 3;
        if (Input::IsKeyPressed(KeyCode::KEY_ESCAPE)) mIsRunning = false;

        if (numFrames % 5 == 0) currentFrame++;
        if (currentFrame > 3)   currentFrame = 0;

        Renderer::Clear();
        Renderer::DrawTexturedRectangle(position, { 64, 205 },
            frames[currentFrame]->texture, frames[currentFrame]->topLeft, frames[currentFrame]->bottomRight);

        Renderer::DrawFilledRectangle({ 0, 450 }, { 500, 50 }, { 0, 0, 0 });
    }

private:

    Vector2d position;
    Texture* texture;

    int         numFrames     = 0;
    int         currentFrame  = 0;
    SubTexture* frames[4];
};

Game* Jem::CreateGame() {
    return new Sandbox();
}
