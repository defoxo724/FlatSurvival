#pragma once

#include "GrassGameObjectModel.hpp"
#include "IWorldGenerator.hpp"
#include "Vec2.hpp"
#include <cstdint>
#include <memory>
#include <utility>

class FlatWorldGenerator : public IWorldGenerator
{
  private:
    std::uint32_t width;
    std::uint32_t height;
    Vec2 position;

  public:
    FlatWorldGenerator(std::uint32_t width, std::uint32_t height, Vec2 position);

    std::vector<std::shared_ptr<IGameObject>> generate() override;
};