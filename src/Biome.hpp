#pragma once

#include "Block.hpp"
#include <cstdint>
class Biome
{
  public:
    std::uint32_t minWidth;
    std::uint32_t maxWidth;
    std::uint32_t minHeight;
    std::uint32_t maxHeight;

    const Block &block;

    Biome(std::uint32_t minWidth, std::uint32_t maxWidth, std::uint32_t minHeight, std::uint32_t maxHeight,
          const Block &block)
        : minWidth(minWidth), maxWidth(maxWidth), minHeight(minHeight), maxHeight(maxHeight), block(block)
    {
    }
};