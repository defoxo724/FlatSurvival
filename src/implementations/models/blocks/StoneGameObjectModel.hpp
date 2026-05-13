#pragma once

#include "AGameObject.hpp"
#include "BasicBlock.hpp"
#include "IGameObject.hpp"
#include "Vec2.hpp"

class StoneGameObjectModel : public BasicBlock
{
  public:
    const std::string TEXTURE_NAME = "STONE";
    const std::string GAME_OBJECT_NAME = "STONE";

    StoneGameObjectModel();

    std::string getObjectName() const override;
    std::string getTextureName() const override;
    void update() override;
};