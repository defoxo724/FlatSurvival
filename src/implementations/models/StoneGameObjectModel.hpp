#pragma once

#include "AGameObject.hpp"
#include "IGameObject.hpp"
#include "Vec2.hpp"

class StoneGameObjectModel : public AGameObject
{
  public:
    const std::string TEXTURE_NAME = "STONE";
    const std::string GAME_OBJECT_NAME = "STONE";
    const Vec2 PIXEL_SIZE = {4, 4};

    StoneGameObjectModel();

    std::string getObjectName() const override;
    std::string getTextureName() const override;
    void update() override;
};