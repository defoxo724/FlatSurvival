#include "AGameObject.hpp"

void AGameObject::setHp(float hp)
{
    this->hp = hp;
}

float AGameObject::getHp() const
{
    return hp;
}

void AGameObject::setMaxHp(float maxHp)
{
    this->maxHp = maxHp;
}

float AGameObject::getMaxHp() const
{
    return maxHp;
}

void AGameObject::setPosition(const Vec2 &position)
{
    this->position = position;
}

Vec2 AGameObject::getPosition() const
{
    return position;
}

void AGameObject::setHitbox(const Vec2 &hitbox)
{
    this->hitbox = hitbox;
}

Vec2 AGameObject::getHitbox() const
{
    return hitbox;
}

void AGameObject::setSize(const Vec2 &size)
{
    this->size = size;
}

Vec2 AGameObject::getSize() const
{
    return size;
}
