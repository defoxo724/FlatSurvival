#pragma once

#include "IGameObject.hpp"
#include <memory>
#include <vector>

class IModelRenderer
{
  public:
    virtual void render(const std::vector<std::shared_ptr<IGameObject>> &gameObjects) = 0;
    virtual ~IModelRenderer() = default;
};