#pragma once

#include "Block.hpp"
#include "Blocks.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include <PerlinNoise.hpp>
#include <array>
#include <cstdint>
#include <sys/types.h>

const std::uint32_t WORLD_HEIGHT = 30;
const std::uint32_t WORLD_WIDTH = 200;

const std::uint8_t BLOCK_SIZE_IN_PIXELS = 32;

/*
    Array 2d bloków o rozmiarach świata.

    Użycie:
        blockArray.at(4).at(10) - X: 4, Y: 10

*/
using WorldSizeBlockArray = std::array<std::array<Block, WORLD_HEIGHT>, WORLD_WIDTH>;

WorldSizeBlockArray blockArray{Blocks::AIR};
sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML works!");