#pragma once

#include "Vec2.hpp"

class IMouseDetector
{
  public:
    virtual Vec2 getMousePositionOnWindow() = 0;
    virtual ~IMouseDetector() = default;
};