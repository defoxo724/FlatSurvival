#pragma once

#include "IGameObject.hpp"

class AGameObject : public IGameObject
{
  protected:
    Vec2 position;
    Vec2 size;
    Vec2 hitbox;

    float hp = 20;
    float maxHp = 20;

  public:
    void setHp(float hp) override;
    float getHp() const override;
    void setMaxHp(float maxHp) override;
    float getMaxHp() const override;

    void setPosition(const Vec2 &position) override;
    Vec2 getPosition() const override;
    void setHitbox(const Vec2 &hitbox) override;
    Vec2 getHitbox() const override;
    void setSize(const Vec2 &size) override;
    Vec2 getSize() const override;
};