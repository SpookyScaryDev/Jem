#pragma once

#include <ECS/ECSManager.h>
#include <Renderer/Camera.h>

namespace Jem {

    void RenderSystem(ECSManager* world, const Camera& camera = { 0.0, 0.0 });

}

