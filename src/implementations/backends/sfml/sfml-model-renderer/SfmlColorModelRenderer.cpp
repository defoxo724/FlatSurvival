#include "SfmlColorModelRenderer.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include <iostream>
#include <stdexcept>

SfmlColorModelRenderer::SfmlColorModelRenderer(sf::RenderWindow &sfmlWindow) : sfmlWindow(sfmlWindow)
{
}

void SfmlColorModelRenderer::render(const std::vector<std::shared_ptr<IGameObject>> &gameObjects)
{
    sf::RectangleShape shape;

    for (auto &el : gameObjects)
    {
        shape.setOrigin({sf::Vector2f{0.0f, 0.0f}});
        shape.setSize(sf::Vector2f{el->getSize().x, el->getSize().y});
        shape.setPosition(sf::Vector2f{el->getPosition().x, el->getPosition().y});
        shape.setFillColor(getModelColorByTextureName(el->getTextureName()));

        sfmlWindow.draw(shape);
    }
}

sf::Color SfmlColorModelRenderer::getModelColorByTextureName(const std::string &textureName)
{
    if (textureName == "PLAYER")
    {
        return sf::Color::Red;
    }

    if (textureName == "GRASS")
    {
        return sf::Color::Green;
    }

    if (textureName == "STONE")
    {
        return sf::Color(100, 100, 100, 255);
    }

    if (textureName == "SAND")
    {
        return sf::Color::Yellow;
    }

    throw std::runtime_error("No colors found for the given texture name");
}
