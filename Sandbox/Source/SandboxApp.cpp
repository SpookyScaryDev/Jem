#include <Jem.h>
#include <string>

using namespace Jem;

struct PhysicsComponent {
    Vector2d velocity  = { 0.0, 0.0 };
    Vector2d drag      = { 0.0, 0.0 };
};

void PhysicsSystem(ECSManager* world, double dt) {
    for (Entity entity : world->GetEntitiesWith<PhysicsComponent, TransformComponent>()) {
        PhysicsComponent&   physics   = world->GetComponent<PhysicsComponent>(entity);
        TransformComponent& transform = world->GetComponent<TransformComponent>(entity);

        if (physics.velocity.x < 0.0) physics.velocity.x += physics.drag.x * dt;
        if (physics.velocity.y > 0.0) physics.velocity.y -= physics.drag.y * dt;
        if (physics.velocity.y < 0.0) physics.velocity.y += physics.drag.y * dt;
        if (physics.velocity.x > 0.0) physics.velocity.x -= physics.drag.x * dt;

        transform.position += physics.velocity;
    }
}

struct PlatformerControllerComponent {};

void PlatformerControllerSystem(ECSManager* world, double dt) {
    for (Entity entity : world->GetEntitiesWith<PlatformerControllerComponent, PhysicsComponent>()) {
        PhysicsComponent& physics = world->GetComponent<PhysicsComponent>(entity);

        if (Input::IsKeyPressed(KeyCode::KEY_UP))    physics.velocity.y -= 2 * dt;
        if (Input::IsKeyPressed(KeyCode::KEY_DOWN))  physics.velocity.y += 2 * dt;
        if (Input::IsKeyPressed(KeyCode::KEY_LEFT))  physics.velocity.x -= 2 * dt;
        if (Input::IsKeyPressed(KeyCode::KEY_RIGHT)) physics.velocity.x += 2 * dt;
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
        Renderer::SetClearColour({ 50, 50, 50 });

        body = CollisionRect();

        body.rect.position = { 100, 500 };
        body.rect.size = { 50, 50 };
        body.rotation = 0;

        base = CollisionRect();

        texture = new Texture("Assets/foo.bmp");
        world.RegisterComponentType<TextureComponent>();
        world.RegisterComponentType<TransformComponent>();
        world.RegisterComponentType<PhysicsComponent>();
        world.RegisterComponentType<PlatformerControllerComponent>();

        for (int i = 10; i >= 0; i--) {
            Entity entity = world.CreateEntity(i);
            world.AddComponent<TextureComponent>(entity, { texture });
            world.AddComponent<TransformComponent>(entity, { Vector2d(625, 200 + i * 20), { 250, 250 } });
            world.AddComponent<PhysicsComponent>(entity, { {}, { 1, 1 },});
            world.AddComponent<PlatformerControllerComponent>(entity, {});
        }
    }

    void OnEvent(Event* event) {
        Game::OnEvent(event);

        switch (event->GetType()) {
        case EventType::KeyPressed:
            if (((KeyPressedEvent*)event)->GetKeyCode() == KeyCode::KEY_GRAVE) Console::Toggle();
            break;
        }
    }

    void Update(double deltaTime) {
        Renderer::Clear();

        if (Input::IsKeyPressed(KeyCode::KEY_ESCAPE)) mIsRunning = false;

        BasicCameraController(camera);
        SpinnySystem(&world);
        PlatformerControllerSystem(&world, deltaTime);
        PhysicsSystem(&world, deltaTime);


        Renderer::BeginScene(camera);
        RenderSystem(&world);
        Renderer::EndScene();

        int fps = int(1000.0 / deltaTime / 1000.0);

        Renderer::DrawString({ 1600 - 35, 0 }, std::to_string(fps).c_str());
    }

private:
    Texture*   texture;
    ECSManager world;
    Camera     camera;

    CollisionRect body;
    CollisionRect base;
};

Game* Jem::CreateGame() {
    return new Sandbox();
}