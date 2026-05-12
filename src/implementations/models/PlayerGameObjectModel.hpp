#pragma once

#include "AABBHelper.hpp"
#include "AGameObject.hpp"
#include "IGameObject.hpp"
#include "Vec2.hpp"
#include <cstdint>

enum class PlayerState
{
    IDLE,
    FALLING,
    JUMPING
};

class PlayerGameObjectModel : public AGameObject
{
  private:
    const std::string TEXTURE_NAME = "PLAYER";
    const std::string GAME_OBJECT_NAME = "PLAYER";

    PlayerState state = PlayerState::FALLING;

    const float GRAVITY = 1500.f;
    const float SPEED = 500.0f;
    const float JUMP_FORCE = -700.0f;

    const int MAX_STEP_HEIGHT = 16;

    float velocityY = 0.0f;

  public:
    PlayerGameObjectModel();

    std::string getObjectName() const override;
    std::string getTextureName() const override;
    void update() override;

    void processState();
    void processMovement();

    bool isOnGround();
};