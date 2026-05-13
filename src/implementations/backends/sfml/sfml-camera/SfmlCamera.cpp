#include "SfmlCamera.hpp"
#include "SFML/System/Vector2.hpp"

SfmlCamera::SfmlCamera(sf::RenderWindow &window) : window(window), view(window.getDefaultView())
{
    window.setView(view);
}

void SfmlCamera::setCenter(const Vec2 &center)
{
    view.setCenter(sf::Vector2f{center.x, center.y});
    window.setView(view);
}