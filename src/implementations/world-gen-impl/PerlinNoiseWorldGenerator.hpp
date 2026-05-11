#pragma once

#include "IWorldGenerator.hpp"
#include "PerlinNoise.hpp"

class PerlinNoiseWorldGenerator : public IWorldGenerator
{
    std::uint32_t width;
    Vec2 position;

  public:
    PerlinNoiseWorldGenerator(std::uint32_t width, Vec2 position);
    std::vector<std::shared_ptr<IGameObject>> generate() override;
};