#pragma once

#include "IGameObject.hpp"
#include <algorithm>
#include <cstdint>
#include <memory>
#include <vector>

class IModelManager
{
  public:
    virtual void addModel(std::shared_ptr<IGameObject> gameObject) = 0;
    virtual void removeModel(std::shared_ptr<IGameObject> gameObject) = 0;
    virtual std::vector<std::shared_ptr<IGameObject>> getGameObjects() const = 0;
    virtual void update() const = 0;
    virtual std::uint64_t size() const = 0;
    virtual ~IModelManager() = default;
};