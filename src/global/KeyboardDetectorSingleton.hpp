#pragma once

#include "IKeyboardDetector.hpp"
#include "Singleton.hpp"

class KeyboardDetectorSingleton : public Singleton<IKeyboardDetector>
{
};