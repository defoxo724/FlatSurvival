#include "SfmlDeltaTime.hpp"

void SfmlDeltaTime::measure()
{
    deltaTime = clock.restart().asSeconds();
}

float SfmlDeltaTime::getDeltaTime()
{
    return deltaTime;
}