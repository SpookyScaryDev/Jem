#pragma once

// Core systems.
#include <Core/Core.h>
#include <Core/Assert.h>            // Assertion macros.

// Entry point.
#include <Core/EntryPoint/EntryPoint.h>

// Application base class.
#include <Core/Game/Game.h>

// Maths.
#include <Core/Maths/Vector2d.h>
#include <Core/Maths/Vector3d.h>
#include <Core/Maths/Vector4d.h>

// Input
#include <Core/Input/Input.h>
#include <Core/Input/KeyCodes.h>
#include <Core/Input/MouseCodes.h>

// Events
#include <Core/Event/EventDispatcher.h>
#include <Core/Event/KeyEvent.h>
#include <Core/Event/MouseEvent.h>
#include <Core/Event/WindowEvent.h>

// Renderer
#include <Renderer/Renderer.h>
#include <Renderer/Texture.h>

// ECS
#include <ECS/ECSManager.h>

// Components
#include <Components/TextureComponent.h>
#include <Components/TransformComponent.h>

// Logger macros / static Log.
#include <Core/Log/Log.h>
