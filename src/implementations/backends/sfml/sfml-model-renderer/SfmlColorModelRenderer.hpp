#pragma once

#include "IModelRenderer.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class SfmlColorModelRenderer : public IModelRenderer
{
  private:
    sf::RenderWindow &sfmlWindow;

  public:
    SfmlColorModelRenderer(sf::RenderWindow &sfmlWindow);
    void render(const std::vector<std::shared_ptr<IGameObject>> &gameObjects) override;

    sf::Color getModelColorByTextureName(const std::string &textureName);
};