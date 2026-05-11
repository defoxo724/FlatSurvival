#pragma once

#include "IGameObject.hpp"
#include <memory>
#include <vector>

class IWorldGenerator
{
  public:
    virtual std::vector<std::shared_ptr<IGameObject>> generate() = 0;
    virtual ~IWorldGenerator() = default;
};