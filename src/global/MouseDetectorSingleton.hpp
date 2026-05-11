#pragma once

#include "IMouseDetector.hpp"
#include "Singleton.hpp"

class MouseDetectorSingleton : public Singleton<IMouseDetector>
{
};

