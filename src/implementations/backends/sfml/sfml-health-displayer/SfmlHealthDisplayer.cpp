#include "SfmlHealthDisplayer.hpp"
#include "SFML/Graphics/Text.hpp"
#include <string>

SfmlHealthDisplayer::SfmlHealthDisplayer(sf::Font &font, sf::RenderWindow &window) : font(font), widnow(window)
{
}

void SfmlHealthDisplayer::displayGameObjectsHealth(std::vector<std::shared_ptr<IGameObject>> gameObjects)
{
    sf::Text text{font};
    for (auto &gameObject : gameObjects)
    {
        std::string str = std::to_string(static_cast<int>(gameObject->getHp())) + " / " +
                          std::to_string(static_cast<int>(gameObject->getHp()));
        text.setString(str);
        text.setPosition({gameObject->getPosition().x, gameObject->getPosition().y - 40});
        widnow.draw(text);
    }
}
