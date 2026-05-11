#pragma once

#include "IDeltaTime.hpp"
#include "IMouseDetector.hpp"
#include "Singleton.hpp"
class DeltaTimeSingleton : public Singleton<IDeltaTime>
{
};