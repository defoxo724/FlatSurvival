#pragma once

#include "Vec2.hpp"

class ICamera
{
  public:
    virtual void setCenter(const Vec2 &center) = 0;
    virtual ~ICamera() = default;
};