#pragma once

#include "ICamera.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/View.hpp"

class SfmlCamera : public ICamera
{
  private:
    sf::RenderWindow &window;
    sf::View view;

  public:
    SfmlCamera(sf::RenderWindow &window);
    void setCenter(const Vec2 &center) override;
};