#pragma once

#include "AGameObject.hpp"
#include "Vec2.hpp"
#include <string>

class BasicBlock : public AGameObject
{
  public:
    /* constant value for EVERY block in the game */
    const Vec2 PIXEL_SIZE = {16, 16};

    BasicBlock();
};
