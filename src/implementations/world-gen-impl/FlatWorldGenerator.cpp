#include "FlatWorldGenerator.hpp"
#include "IGameObject.hpp"
#include <memory>

FlatWorldGenerator::FlatWorldGenerator(std::uint32_t width, std::uint32_t height, Vec2 position)
    : width(width), height(height), position(position)
{
}

std::vector<std::shared_ptr<IGameObject>> FlatWorldGenerator::generate()
{
    std::vector<std::shared_ptr<IGameObject>> gameObjects;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            std::shared_ptr<IGameObject> grass = std::make_shared<GrassGameObjectModel>();
            grass->setPosition({static_cast<float>(position.x + (i * grass->getSize().x)),
                                static_cast<float>(position.y + (j * grass->getSize().y))});
            grass->update();
            gameObjects.push_back(grass);
        }
    }
    return gameObjects;
}
