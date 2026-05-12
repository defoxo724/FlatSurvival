#pragma once

#include "AGameObject.hpp"
#include "IGameObject.hpp"
#include "Vec2.hpp"

class SandGameObjectModel : public AGameObject
{
  public:
    const std::string TEXTURE_NAME = "SAND";
    const std::string GAME_OBJECT_NAME = "SAND";
    const Vec2 PIXEL_SIZE = {4, 4};

    SandGameObjectModel();

    std::string getObjectName() const override;
    std::string getTextureName() const override;
    void update() override;
};