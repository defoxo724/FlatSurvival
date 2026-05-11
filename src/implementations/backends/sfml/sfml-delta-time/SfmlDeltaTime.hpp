#pragma once

#include "IDeltaTime.hpp"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

class SfmlDeltaTime : public IDeltaTime
{
  private:
    sf::Clock clock;
    float deltaTime;

  public:
    void measure() override;
    float getDeltaTime() override;
};