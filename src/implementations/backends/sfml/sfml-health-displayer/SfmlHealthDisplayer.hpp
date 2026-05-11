#pragma once

#include "IHealthDisplayer.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class SfmlHealthDisplayer : public IHealthDisplayer
{
    sf::Font &font;
    sf::RenderWindow &widnow;

  public:
    SfmlHealthDisplayer(sf::Font &font, sf::RenderWindow &window);
    void displayGameObjectsHealth(std::vector<std::shared_ptr<IGameObject>> gameObjects) override;
};