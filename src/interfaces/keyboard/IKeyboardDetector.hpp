#pragma once

#include "Key.hpp"
class IKeyboardDetector
{
  public:
    virtual bool isKeyPressed(Key key) = 0;
    virtual ~IKeyboardDetector() = default;
};