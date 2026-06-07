#pragma once

#include "AABBHelper.hpp"
#include "IGameObject.hpp"
#include "ModelManagerSingleton.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"
#include <memory>

class BlockBreaker
{

  public:
    static const int AREA;
    static const int MINING_AREA;

    void breakBlocks(sf::RenderWindow &window);
};