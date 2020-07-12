#include <Jem.h>

using namespace Jem;

struct SpriteComponent {
    Texture*        texture;
    Vector2d        topLeft;
    Vector2d        bottomRight;
    bool            isFlippedVertical;
    bool            isFlippedHorizontal;
};

struct TransformComponent {
    Vector2d        position;
};

void RenderSystem(ECSManager* world, double dt) {
    for (Entity entity : world->GetEntitiesWith<SpriteComponent, TransformComponent>()) {
        SpriteComponent sprite = world->GetComponent<SpriteComponent>(entity);
        TransformComponent transform = world->GetComponent<TransformComponent>(entity);

        Renderer::DrawTexturedRectangle(
            transform.position,
            { 500, 500 },
            sprite.texture,
            sprite.topLeft,
            sprite.bottomRight,
            sprite.isFlippedHorizontal,
            sprite.isFlippedVertical
        );
    }
}

class Sandbox : public Game {
public:
    Sandbox() : Game("Sandbox", 500, 500) {
        texture = new Texture("Assets/foo.bmp");
        world.RegisterComponentType<SpriteComponent>();
        world.RegisterComponentType<TransformComponent>();

        entity1 = world.CreateEntity(1);
        world.AddComponent<SpriteComponent>(entity1, { texture, {0.0,0.0}, {1.0,1.0}, false, false });
        world.AddComponent<TransformComponent>(entity1, { {0, 0} });

        entity2 = world.CreateEntity(2);
        world.AddComponent<SpriteComponent>(entity2, { texture, {0.0,0.0}, {1.0,1.0}, false, false });
        world.AddComponent<TransformComponent>(entity2, { {0, 10} });

        entity3 = world.CreateEntity(3);
        world.AddComponent<SpriteComponent>(entity3, { texture, {0.0,0.0}, {1.0,1.0}, false, false });
        world.AddComponent<TransformComponent>(entity3, { {0, 20} });

    }

    void Update(double deltaTime) {
        RenderSystem(&world, deltaTime);
        Renderer::Refresh();
    }

private:
    Texture*   texture;
    Entity     entity1;
    Entity     entity2;
    Entity     entity3;
    ECSManager world;
};

Game* Jem::CreateGame() {
    return new Sandbox();
}
