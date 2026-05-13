#include "PerlinNoiseWorldGenerator.hpp"
#include "GrassGameObjectModel.hpp"
#include "SandGameObjectModel.hpp"
#include "StoneGameObjectModel.hpp"

#include <iostream>

PerlinNoiseWorldGenerator::PerlinNoiseWorldGenerator(std::uint32_t width, Vec2 position)
    : width(width), position(position)
{
}

std::vector<std::shared_ptr<IGameObject>> PerlinNoiseWorldGenerator::generate()
{
    std::vector<std::shared_ptr<IGameObject>> gameObjects;

    const siv::PerlinNoise perlin{static_cast<uint32_t>(rand())};

    const double terrainScale = 0.005;
    const double biomeScale = 0.0015;

    const int maxHeight = 100;

    for (int i = 0; i < width; ++i)
    {
        double terrainNoise = perlin.noise1D(i * terrainScale);

        int height = static_cast<int>((terrainNoise + 1.0) * 0.5 * maxHeight);

        double biomeNoise = perlin.noise1D((i + 99999) * biomeScale);

        bool isDesertBiome = biomeNoise > 0.1;

        for (int j = 0; j < height; ++j)
        {
            std::shared_ptr<IGameObject> block;

            bool isSurfaceBlock = (j == height - 1);

            int stoneStartDepth = 10 + rand() % 11;

            bool shouldBeStone = j < (height - stoneStartDepth);

            if (shouldBeStone)
            {
                block = std::make_shared<StoneGameObjectModel>();
            }
            else
            {
                if (isDesertBiome)
                {
                    block = std::make_shared<SandGameObjectModel>();
                }
                else
                {
                    block = std::make_shared<GrassGameObjectModel>();
                }
            }

            float tileW = block->getSize().x;
            float tileH = block->getSize().y;

            std::cout << tileW << std::endl;

            float xPos = position.x + i * tileW;
            float yPos = position.y - j * tileH;

            block->setPosition({xPos, yPos});
            block->update();

            gameObjects.push_back(block);
        }
    }

    return gameObjects;
}