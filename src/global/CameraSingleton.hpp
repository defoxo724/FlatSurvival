#pragma once

#include "ICamera.hpp"
#include "Singleton.hpp"

class CameraSingleton : public Singleton<ICamera>
{
};
