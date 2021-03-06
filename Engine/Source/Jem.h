#pragma once

// Core systems.
#include <Core/Core.h>
#include <Core/Assert.h>

// Entry point.
#include <Core/EntryPoint/EntryPoint.h>

// Application base class.
#include <Core/Game/Game.h>

// Maths.
#include <Core/Maths/Vector2d.h>
#include <Core/Maths/Vector3d.h>
#include <Core/Maths/Vector4d.h>
#include <Core/Maths/Rectangle.h>

// Input
#include <Core/Input/Input.h>
#include <Core/Input/KeyCodes.h>
#include <Core/Input/MouseCodes.h>

// Events
#include <Core/Event/EventDispatcher.h>
#include <Core/Event/KeyEvent.h>
#include <Core/Event/MouseEvent.h>
#include <Core/Event/WindowEvent.h>
#include <Core/Event/TextEvent.h>

// Console
#include <Core/Console/Console.h>

// Renderer
#include <Renderer/Renderer.h>
#include <Renderer/Texture.h>
#include <Renderer/Camera.h>
#include <Renderer/BasicCameraController.h>

// Collision Detection
#include <Collision/Collision.h>
#include <Collision/CollisionPoly.h>
#include <Collision/CollisionRect.h>

// ECS
#include <ECS/ECSManager.h>

// Components
#include <Components/TextureComponent.h>
#include <Components/TransformComponent.h>

// Systems
#include <Systems/RenderSystem.h>
