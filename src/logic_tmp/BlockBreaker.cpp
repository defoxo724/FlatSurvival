#include "BlockBreaker.hpp"

const int BlockBreaker::AREA = 50;
const int BlockBreaker::MINING_AREA = 200;

void BlockBreaker::breakBlocks(sf::RenderWindow &window)
{
    sf::Vector2i windowPos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePos = window.mapPixelToCoords(windowPos);
    std::shared_ptr<IGameObject> player;
    for (auto &el : ModelManagerSingleton::getInstance()->getObject()->getGameObjects())
    {
        if (el->getObjectName() == "PLAYER")
        {
            player = el;
            break;
        }
    }
    if (AABBHelper::isColliding(player->getPosition(), player->getHitbox(),
                                Vec2{mousePos.x - MINING_AREA, mousePos.y - MINING_AREA},
                                Vec2{MINING_AREA * 2, MINING_AREA * 2}))
    {

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            for (auto &el : ModelManagerSingleton::getInstance()->getObject()->getGameObjects())
            {
                if (AABBHelper::isColliding(Vec2{mousePos.x, mousePos.y}, Vec2{AREA, AREA}, el->getPosition(),
                                            el->getHitbox()))
                {
                    if (el->getObjectName() != "PLAYER")
                    {
                        ModelManagerSingleton::getInstance()->getObject()->removeModel(el);
                    }
                }
            }
        }
    }
}
