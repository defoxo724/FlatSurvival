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

bool PlayerGameObjectModel::isOnGround()
{
    Vec2 testPosition = {getPosition().x, getPosition().y + 1.0f};

    for (auto &el : ModelManagerSingleton::getInstance()->getObject()->getGameObjects())
    {
        if (el.get() == this)
        {
            continue;
        }

        if (AABBHelper::isColliding(el->getPosition(), el->getHitbox(), testPosition, getHitbox()))
        {
            return true;
        }
    }

    return false;
}

void PlayerGameObjectModel::processState()
{
    float deltaTime = DeltaTimeSingleton::getInstance()->getObject()->getDeltaTime();

    if (isOnGround())
    {
        if (velocityY > 0)
        {
            velocityY = 0;
        }

        if (KeyboardDetectorSingleton::getInstance()->getObject()->isKeyPressed(Key::SPACE))
        {
            velocityY = JUMP_FORCE;
            state = PlayerState::JUMPING;
        }
        else
        {
            state = PlayerState::IDLE;
        }
    }
    else
    {
        velocityY += GRAVITY * deltaTime;

        if (velocityY < 0)
        {
            state = PlayerState::JUMPING;
        }
        else
        {
            state = PlayerState::FALLING;
        }
    }

    Vec2 oldPosition = getPosition();

    setPosition({getPosition().x, getPosition().y + velocityY * deltaTime});

    for (auto &el : ModelManagerSingleton::getInstance()->getObject()->getGameObjects())
    {
        if (el.get() == this)
        {
            continue;
        }

        if (AABBHelper::isColliding(el->getPosition(), el->getHitbox(), getPosition(), getHitbox()))
        {
            setPosition(oldPosition);

            if (velocityY > 0)
            {
                velocityY = 0;
                state = PlayerState::IDLE;
            }
        }
    }
}

void PlayerGameObjectModel::processMovement()
{
    float deltaTime = DeltaTimeSingleton::getInstance()->getObject()->getDeltaTime();

    float moveX = 0.0f;

    if (KeyboardDetectorSingleton::getInstance()->getObject()->isKeyPressed(Key::A))
    {
        moveX -= SPEED * deltaTime;
    }

    if (KeyboardDetectorSingleton::getInstance()->getObject()->isKeyPressed(Key::D))
    {
        moveX += SPEED * deltaTime;
    }

    Vec2 oldPosition = getPosition();

    setPosition({getPosition().x + moveX, getPosition().y});

    bool collision = false;

    for (auto &el : ModelManagerSingleton::getInstance()->getObject()->getGameObjects())
    {
        if (el.get() == this)
        {
            continue;
        }

        if (AABBHelper::isColliding(el->getPosition(), el->getHitbox(), getPosition(), getHitbox()))
        {
            collision = true;
            break;
        }
    }

    if (collision)
    {
        bool stepped = false;

        for (int i = 1; i <= MAX_STEP_HEIGHT; i++)
        {
            setPosition({oldPosition.x + moveX, oldPosition.y - static_cast<float>(i)});

            bool stillColliding = false;

            for (auto &el : ModelManagerSingleton::getInstance()->getObject()->getGameObjects())
            {
                if (el.get() == this)
                {
                    continue;
                }

                if (AABBHelper::isColliding(el->getPosition(), el->getHitbox(), getPosition(), getHitbox()))
                {
                    stillColliding = true;
                    break;
                }
            }

            if (!stillColliding)
            {
                stepped = true;
                break;
            }
        }

        if (!stepped)
        {
            setPosition(oldPosition);
        }
    }
}