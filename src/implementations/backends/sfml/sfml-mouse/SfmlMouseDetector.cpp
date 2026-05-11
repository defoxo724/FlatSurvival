#include "SfmlMouseDetector.hpp"
#include "SFML/Window/Mouse.hpp"
#include "Vec2.hpp"

SfmlMouseDetector::SfmlMouseDetector(sf::RenderWindow &window) : window(window)
{
}

Vec2 SfmlMouseDetector::getMousePositionOnWindow()
{
    auto sfmlPos = sf::Mouse::getPosition(window);
    return Vec2{static_cast<float>(sfmlPos.x), static_cast<float>(sfmlPos.y)};
}
