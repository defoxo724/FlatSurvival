#pragma once

#include "IMouseDetector.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class SfmlMouseDetector : public IMouseDetector
{
    sf::RenderWindow &window;

  public:
    explicit SfmlMouseDetector(sf::RenderWindow &window);
    Vec2 getMousePositionOnWindow() override;
};