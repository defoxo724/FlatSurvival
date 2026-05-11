#pragma once

class IDeltaTime
{
  public:
    virtual void measure() = 0;
    virtual float getDeltaTime() = 0;
    virtual ~IDeltaTime() = default;
};