#pragma once

#include "IGameObject.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <memory>
#include <vector>

class IHealthDisplayer
{
  public:
    virtual void displayGameObjectsHealth(std::vector<std::shared_ptr<IGameObject>> gameObjects) = 0;
    virtual ~IHealthDisplayer() = default;
};