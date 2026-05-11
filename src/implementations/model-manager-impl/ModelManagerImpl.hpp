#pragma once

#include "IModelManager.hpp"

class ModelManagerImpl : public IModelManager
{
    std::vector<std::shared_ptr<IGameObject>> gameObjects;

  public:
    void addModel(std::shared_ptr<IGameObject> gameObject) override;
    void removeModel(std::shared_ptr<IGameObject> gameObject) override;
    std::vector<std::shared_ptr<IGameObject>> getGameObjects() const override;
    void update() const override;
    std::uint64_t size() const override;
};