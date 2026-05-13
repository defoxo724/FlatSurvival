#pragma once

#include "AGameObject.hpp"
#include "BasicBlock.hpp"
#include "IGameObject.hpp"
#include "Vec2.hpp"

class GrassGameObjectModel : public BasicBlock
{
  public:
    const std::string TEXTURE_NAME = "GRASS";
    const std::string GAME_OBJECT_NAME = "GRASS";

    GrassGameObjectModel();

    std::string getObjectName() const override;
    std::string getTextureName() const override;
    void update() override;
};