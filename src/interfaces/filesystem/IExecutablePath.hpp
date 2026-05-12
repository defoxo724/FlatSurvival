#pragma once

#include <string>

class IExecutablePath
{
  public:
    virtual std::string get() const = 0;
    virtual ~IExecutablePath() = default;
};