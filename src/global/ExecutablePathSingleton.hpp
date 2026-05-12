#pragma once

#include "IExecutablePath.hpp"
#include "Singleton.hpp"

class ExecutablePathSingleton : public Singleton<IExecutablePath>
{
};