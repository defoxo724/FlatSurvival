#pragma once

#include "Vec2.hpp"
#include <string>

class IGameObject
{
  public:
    virtual void setPosition(const Vec2 &position) = 0;
    virtual Vec2 getPosition() const = 0;

    virtual void setHitbox(const Vec2 &hitbox) = 0;
    virtual Vec2 getHitbox() const = 0;

    virtual void setSize(const Vec2 &size) = 0;
    virtual Vec2 getSize() const = 0;

    virtual std::string getObjectName() const = 0;
    virtual std::string getTextureName() const = 0;

    virtual void setHp(float hp) = 0;
    virtual float getHp() const = 0;
    virtual void setMaxHp(float maxHp) = 0;
    virtual float getMaxHp() const = 0;

    virtual void update() = 0;

    virtual ~IGameObject() = default;
};