#include "PerlinNoiseWorldGenerator.hpp"
#include "GrassGameObjectModel.hpp"
#include <iostream>

PerlinNoiseWorldGenerator::PerlinNoiseWorldGenerator(std::uint32_t width, Vec2 position)
    : width(width), position(position)
{
}

std::vector<std::shared_ptr<IGameObject>> PerlinNoiseWorldGenerator::generate()
{
    std::vector<std::shared_ptr<IGameObject>> gameObjects;
    const siv::PerlinNoise perlin{static_cast<uint32_t>(rand())};

    const double scale = 0.005;
    const int maxHeight = 100;

    for (int i = 0; i < width; ++i)
    {
        double noise = perlin.noise1D(i * scale);

        int height = static_cast<int>((noise + 1.0) * 0.5 * maxHeight);

        for (int j = 0; j < height; ++j)
        {
            auto grass = std::make_shared<GrassGameObjectModel>();

            float tileW = grass->getSize().x;
            float tileH = grass->getSize().y;

            float xPos = position.x + i * tileW;
            float yPos = position.y - j * tileH;

            grass->setPosition({xPos, yPos});
            grass->update();

            gameObjects.push_back(grass);
        }
        std::cout << "x: " << i << " -> height: " << height << "\n";
    }

    return gameObjects;
}
