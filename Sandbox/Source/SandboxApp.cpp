#include <Jem.h>

using namespace Jem;

struct PhysicsComponent {
    Vector2d velocity  = { 0.0, 0.0 };
    Vector2d drag      = { 0.0, 0.0 };
    //Vector2d gravity   = { 0.0, 0.0 };
};

void PhysicsSystem(ECSManager* world) {
    for (Entity entity : world->GetEntitiesWith<PhysicsComponent, TransformComponent>()) {
        PhysicsComponent&   physics   = world->GetComponent<PhysicsComponent>(entity);
        TransformComponent& transform = world->GetComponent<TransformComponent>(entity);

        if (physics.velocity.x < 0.0) physics.velocity.x += physics.drag.x;
        if (physics.velocity.y > 0.0) physics.velocity.y -= physics.drag.y;
        if (physics.velocity.y < 0.0) physics.velocity.y += physics.drag.y;
        if (physics.velocity.x > 0.0) physics.velocity.x -= physics.drag.x;

        transform.position += physics.velocity;
    }
}

struct PlatformerControllerComponent {};

void PlatformerControllerSystem(ECSManager* world) {
    for (Entity entity : world->GetEntitiesWith<PlatformerControllerComponent, PhysicsComponent>()) {
        PhysicsComponent& physics = world->GetComponent<PhysicsComponent>(entity);

        if (Input::IsKeyPressed(KeyCode::KEY_UP))    physics.velocity.y -= 2;
        if (Input::IsKeyPressed(KeyCode::KEY_DOWN))  physics.velocity.y += 2;
        if (Input::IsKeyPressed(KeyCode::KEY_LEFT))  physics.velocity.x -= 2;
        if (Input::IsKeyPressed(KeyCode::KEY_RIGHT)) physics.velocity.x += 2;
    }
}

void SpinnySystem(ECSManager* world) {
    for (Entity entity : world->GetEntitiesWith<TransformComponent, PhysicsComponent>()) {
        TransformComponent& transform = world->GetComponent<TransformComponent>(entity);
        PhysicsComponent&   physics   = world->GetComponent<PhysicsComponent>(entity);

        transform.rotation += physics.velocity.x / 10;
        if (transform.rotation == 360) transform.rotation = 0;
    }
}

class Sandbox : public Game {
public:
    Sandbox() : Game("Sandbox", 1600, 900) {
        texture = new Texture("Assets/foo.bmp");
        world.RegisterComponentType<TextureComponent>();
        world.RegisterComponentType<TransformComponent>();
        world.RegisterComponentType<PhysicsComponent>();
        world.RegisterComponentType<PlatformerControllerComponent>();

        for (int i = 10; i >= 0; i--) {
            Entity entity = world.CreateEntity(i);
            world.AddComponent<TextureComponent>(entity, { texture });
            world.AddComponent<TransformComponent>(entity, { Vector2d(Window::GetWidth() / 2 - 125, Window::GetHeight() / 2 - 125 + 20 * i ), { 250, 250 } });
            world.AddComponent<PhysicsComponent>(entity, { {}, { 1, 1 },});
            world.AddComponent<PlatformerControllerComponent>(entity, {});
        }
    }

    void Update(double deltaTime) {
        Renderer::Clear();

        if (Input::IsKeyPressed(KeyCode::KEY_W)) camera.y -= 10;
        if (Input::IsKeyPressed(KeyCode::KEY_S)) camera.y += 10;
        if (Input::IsKeyPressed(KeyCode::KEY_D)) camera.x += 10;
        if (Input::IsKeyPressed(KeyCode::KEY_A)) camera.x -= 10;

        if (Input::IsKeyPressed(KeyCode::KEY_ESCAPE)) mIsRunning = false;

        SpinnySystem(&world);
        RenderSystem(&world, camera);
        PlatformerControllerSystem(&world);
        PhysicsSystem(&world);
        Renderer::Refresh();
    }

private:
    Texture*   texture;
    ECSManager world;
    Camera     camera;
};

Game* Jem::CreateGame() {
    return new Sandbox();
}