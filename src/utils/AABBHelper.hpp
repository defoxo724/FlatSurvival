#pragma once

#include "Vec2.hpp"

class AABBHelper
{
  public:
    static bool isColliding(const Vec2 &positionA, const Vec2 &hitboxA, const Vec2 &positionB, const Vec2 &hitboxB)
    {
        return positionA.x < positionB.x + hitboxB.x && positionA.x + hitboxA.x > positionB.x &&
               positionA.y < positionB.y + hitboxB.y && positionA.y + hitboxA.y > positionB.y;
    }
};