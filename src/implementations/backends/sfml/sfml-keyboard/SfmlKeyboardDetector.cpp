#include "SfmlKeyboardDetector.hpp"

bool SfmlKeyBoardDetector::isKeyPressed(Key key)
{
    switch (key)
    {
    case Key::W:
        return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
    case Key::A:
        return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
    case Key::S:
        return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
    case Key::D:
        return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
    case Key::SPACE:
        return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
        break;
    }
}
