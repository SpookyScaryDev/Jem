#include <Jem.h>

using namespace Jem;

struct PhysicsComponent {
    Vector2d velocity  = { 0.0, 0.0 };
    Vector2d drag      = { 0.0, 0.0 };
    //Vector2d gravity   = { 0.0, 0.0 };
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
        body = CollisionRect();

        body.position = { 100, 500 };
        body.size = { 50, 50 };
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

    void Update(double deltaTime) {
        Renderer::Clear();

        if (Input::IsKeyPressed(KeyCode::KEY_ESCAPE)) mIsRunning = false;

        BasicCameraController(camera);
        SpinnySystem(&world);
        PlatformerControllerSystem(&world);
        PhysicsSystem(&world);


        Renderer::BeginScene(camera);
        RenderSystem(&world);
        //Renderer::DrawFilledRectangle({ 0,0 }, { 500,500 }, { 0,255,0 });
        //Renderer::DrawRectangle({ 0,0 }, { 500,500 }, { 255,0,0 });
        //Renderer::DrawLine({ 0,0 }, { 500, 500 }, { 255, 0, 0 });

        base.position = world.GetComponent<TransformComponent>(10).position;
        base.rotation = world.GetComponent<TransformComponent>(10).rotation;
        base.size = { 250, 250 };

        JEM_WARNING("Collision: ", Collision::RectVsRect(base, body));

        Renderer::EndScene();

        Renderer::Refresh();
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