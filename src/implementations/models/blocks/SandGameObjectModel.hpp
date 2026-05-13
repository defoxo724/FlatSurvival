#pragma once

#include "AGameObject.hpp"
#include "BasicBlock.hpp"
#include "IGameObject.hpp"
#include "Vec2.hpp"

class SandGameObjectModel : public BasicBlock
{
  public:
    const std::string TEXTURE_NAME = "SAND";
    const std::string GAME_OBJECT_NAME = "SAND";

    SandGameObjectModel();

    std::string getObjectName() const override;
    std::string getTextureName() const override;
    void update() override;
};