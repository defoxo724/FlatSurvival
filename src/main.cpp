#include "Blocks.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <PerlinNoise.hpp>
#include <array>
#include <cstdint>
#include <sys/types.h>
#include <vector>

const std::uint32_t WORLD_HEIGHT = 20;
const std::uint32_t WORLD_WIDTH = 200;

const std::uint8_t BLOCK_SIZE_IN_PIXELS = 32;

/*
    Array 2d bloków o rozmiarach świata.

    Użycie:
        blockArray.at(4).at(10) - X: 4, Y: 10

*/
using WorldSizeBlockArray = std::array<std::array<Block, WORLD_HEIGHT>, WORLD_WIDTH>;
WorldSizeBlockArray blockArray;
sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML works!");

void generateWorld()
{
    const siv::PerlinNoise terrainNoise{12345u};
    const siv::PerlinNoise bedrockNoise{54321u};

    for (std::uint32_t x = 0; x < WORLD_WIDTH; x++)
    {
        // Teren mniej więcej w połowie wysokości świata
        double noise = terrainNoise.octave1D_01(x * 0.08, 4);

        int baseHeight = WORLD_HEIGHT / 2;
        int terrainHeight = baseHeight + static_cast<int>((noise - 0.5) * 6);

        // Ograniczenie, żeby teren nie wyszedł poza świat
        terrainHeight = std::clamp(terrainHeight, 2, static_cast<int>(WORLD_HEIGHT - 4));

        // Ilość warstw dirta pod trawą: 2-5
        int dirtLayers = 2 + static_cast<int>(noise * 4);

        // Bedrock: zawsze ostatnia warstwa, czasem 1 kratka wyżej
        double bedrockValue = bedrockNoise.octave1D_01(x * 0.4, 2);
        int bedrockHeight = bedrockValue > 0.55 ? 2 : 1;

        for (std::uint32_t y = 0; y < WORLD_HEIGHT; y++)
        {
            if (y < terrainHeight)
            {
                blockArray.at(x).at(y) = Blocks::AIR;
            }
            else if (y == terrainHeight)
            {
                blockArray.at(x).at(y) = Blocks::GRASS;
            }
            else if (y <= terrainHeight + dirtLayers)
            {
                blockArray.at(x).at(y) = Blocks::DIRT;
            }
            else if (y >= WORLD_HEIGHT - bedrockHeight)
            {
                blockArray.at(x).at(y) = Blocks::BEDROCK;
            }
            else
            {
                blockArray.at(x).at(y) = Blocks::STONE;
            }
        }
    }
}

int main()
{
    generateWorld();
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Block rendering
        sf::RectangleShape blockDrawer;
        blockDrawer.setSize(sf::Vector2f{BLOCK_SIZE_IN_PIXELS, BLOCK_SIZE_IN_PIXELS});
        for (int x = 0; x < blockArray.size(); x++)
        {
            for (int y = 0; y < blockArray[x].size(); y++)
            {
                blockDrawer.setPosition(sf::Vector2f(x * BLOCK_SIZE_IN_PIXELS, y * BLOCK_SIZE_IN_PIXELS));
                blockDrawer.setFillColor(blockArray.at(x).at(y).renderedColor);
                window.draw(blockDrawer);
            }
        }

        window.display();
    }
}