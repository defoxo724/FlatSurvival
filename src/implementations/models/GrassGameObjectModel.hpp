#pragma once

#include "AGameObject.hpp"
#include "IGameObject.hpp"
#include "Vec2.hpp"

class GrassGameObjectModel : public AGameObject
{
  public:
    const std::string TEXTURE_NAME = "GRASS";
    const std::string GAME_OBJECT_NAME = "GRASS";
    const Vec2 PIXEL_SIZE = {4, 4};

    GrassGameObjectModel();

    std::string getObjectName() const override;
    std::string getTextureName() const override;
    void update() override;
};