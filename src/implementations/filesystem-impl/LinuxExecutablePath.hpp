#pragma once

#include "IExecutablePath.hpp"
class LinuxExecutablePath : public IExecutablePath
{
  public:
    std::string get() const override;
};