#pragma once

#include "IModelManager.hpp"
#include "IMouseDetector.hpp"
#include "Singleton.hpp"

class ModelManagerSingleton : public Singleton<IModelManager>
{
};