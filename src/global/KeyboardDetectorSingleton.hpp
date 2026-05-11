#pragma once

#include "IKeyboardDetector.hpp"
#include "IMouseDetector.hpp"
#include "Singleton.hpp"

class KeyboardDetectorSingleton : public Singleton<IKeyboardDetector>
{
};