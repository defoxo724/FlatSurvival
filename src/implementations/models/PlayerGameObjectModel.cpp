#include "PlayerGameObjectModel.hpp"
#include "DeltaTimeSingleton.hpp"
#include "Key.hpp"
#include "KeyboardDetectorSingleton.hpp"
#include "ModelManagerSingleton.hpp"
#include "Vec2.hpp"

PlayerGameObjectModel::PlayerGameObjectModel()
{
    setSize(Vec2{64.0f, 128.0f});
    setHitbox(Vec2{64.0f, 128.0f});
}

std::string PlayerGameObjectModel::getObjectName() const
{
    return GAME_OBJECT_NAME;
}

std::string PlayerGameObjectModel::getTextureName() const
{
    return TEXTURE_NAME;
}

void PlayerGameObjectModel::update()
{
    processState();
    processMovement();
}

void PlayerGameObjectModel::processState()
{

    // TO DZIAŁA
    if (state == PlayerState::FALLING)
    {
        setPosition({getPosition().x,
                     (getPosition().y) + GRAVITY * DeltaTimeSingleton::getInstance()->getObject()->getDeltaTime()});
        // Iterowanie po każdym modelu. Jeśli koliduje z czymkolwiek to zmienia stan na IDLE
        for (auto &el : ModelManagerSingleton::getInstance()->getObject()->getGameObjects())
        {
            if (el.get() == this)
            {
                continue;
            }
            if (AABBHelper::isColliding(el->getPosition(), el->getHitbox(), getPosition(), getHitbox()))
            {
                state = PlayerState::IDLE;
            }
        }
    }

    if (state == PlayerState::IDLE)
    {
        if (KeyboardDetectorSingleton::getInstance()->getObject()->isKeyPressed(Key::SPACE))
        {
            state = PlayerState::JUMPING;
            jumpSteps = MAX_JUMP_STEPS;
        }
    }

    if (state == PlayerState::JUMPING)
    {
        setPosition({getPosition().x,
                     (getPosition().y) - GRAVITY * DeltaTimeSingleton::getInstance()->getObject()->getDeltaTime()});
        jumpSteps--;
        if (jumpSteps <= 0)
        {
            state = PlayerState::FALLING;
        }
    }
}

void PlayerGameObjectModel::processMovement()
{
    if (KeyboardDetectorSingleton::getInstance()->getObject()->isKeyPressed(Key::A))
    {
        setPosition({getPosition().x - (SPEED * DeltaTimeSingleton::getInstance()->getObject()->getDeltaTime()),
                     getPosition().y});
    }
    if (KeyboardDetectorSingleton::getInstance()->getObject()->isKeyPressed(Key::D))
    {
        setPosition({getPosition().x + (SPEED * DeltaTimeSingleton::getInstance()->getObject()->getDeltaTime()),
                     getPosition().y});
    }
}
