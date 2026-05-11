#pragma once

#include "IModelRenderer.hpp"
#include "IMouseDetector.hpp"
#include "Singleton.hpp"
class ModelRendererSingleton : public Singleton<IModelRenderer>
{
};