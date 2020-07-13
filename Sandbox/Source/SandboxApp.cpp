#include <Jem.h>

using namespace Jem;

void SpinnySystem(ECSManager* world) {
    static double angle = 0;
    angle += 0.2;
    
    for (Entity entity : world->GetEntitiesWith<TransformComponent>()) {
        TransformComponent& transform = world->GetComponent<TransformComponent>(entity);

        if (angle == 360) angle = 0;

        transform.rotation = angle;
    }
}

class Sandbox : public Game {
public:
    Sandbox() : Game("Sandbox", 500, 500) {
        texture = new Texture("Assets/foo.bmp");
        world.RegisterComponentType<TextureComponent>();
        world.RegisterComponentType<TransformComponent>();

        for (int i = 10; i >= 0; i--) {
            Entity entity = world.CreateEntity(i);
            world.AddComponent<TextureComponent>(entity, { texture });
            world.AddComponent<TransformComponent>(entity, { {125, double(20 + 20 * i) }, { 250, 250 } });
        }
    }

    void Update(double deltaTime) {
        Renderer::Clear();
        SpinnySystem(&world);
        RenderSystem(&world);
        Renderer::Refresh();
    }

private:
    Texture*   texture;
    ECSManager world;
};

Game* Jem::CreateGame() {
    return new Sandbox();
}