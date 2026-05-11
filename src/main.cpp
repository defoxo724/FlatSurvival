#include "DeltaTimeSingleton.hpp"
#include "IHealthDisplayer.hpp"
#include "KeyboardDetectorSingleton.hpp"
#include "ModelManagerImpl.hpp"
#include "ModelManagerSingleton.hpp"
#include "ModelRendererSingleton.hpp"
#include "MouseDetectorSingleton.hpp"
#include "PerlinNoiseWorldGenerator.hpp"
#include "PlayerGameObjectModel.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/System/Vector2.hpp"
#include "SfmlColorModelRenderer.hpp"
#include "SfmlDeltaTime.hpp"
#include "SfmlHealthDisplayer.hpp"
#include "SfmlKeyboardDetector.hpp"
#include "SfmlMouseDetector.hpp"
#include "Vec2.hpp"
#include <SFML/Graphics.hpp>
#include <cstddef>
#include <ctime>
#include <filesystem>
#include <memory>

int main()
{

    sf::Font font{"./assets/fonts/PixelifySans-Bold.ttf"};
    sf::Text text{font};
    text.setString("XDDD");

    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML works!");
    window.setFramerateLimit(240);

    KeyboardDetectorSingleton::getInstance()->setObject(std::make_shared<SfmlKeyBoardDetector>());
    ModelRendererSingleton::getInstance()->setObject(std::make_shared<SfmlColorModelRenderer>(window));
    MouseDetectorSingleton::getInstance()->setObject(std::make_shared<SfmlMouseDetector>(window));
    DeltaTimeSingleton::getInstance()->setObject(std::make_shared<SfmlDeltaTime>());

    ModelManagerSingleton::getInstance()->setObject(std::make_shared<ModelManagerImpl>());
    auto go = std::make_shared<PlayerGameObjectModel>();
    ModelManagerSingleton::getInstance()->getObject()->addModel(go);

    go->setPosition({300, 300});

    std::shared_ptr<IHealthDisplayer> healthDisplayer = std::make_shared<SfmlHealthDisplayer>(font, window);
    // std::shared_ptr<IWorldGenerator> worldGen = std::make_shared<FlatWorldGenerator>(100, 30, Vec2{100, 500});
    std::shared_ptr<IWorldGenerator> worldGen = std::make_shared<PerlinNoiseWorldGenerator>(500, Vec2{200, 900});
    auto blocks = worldGen->generate();

    for (auto &block : blocks)
    {
        ModelManagerSingleton::getInstance()->getObject()->addModel(block);
    }

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(text);
        ModelManagerSingleton::getInstance()->getObject()->update();
        ModelRendererSingleton::getInstance()->getObject()->render(
            ModelManagerSingleton::getInstance()->getObject()->getGameObjects());

        // healthDisplayer->displayGameObjectsHealth(
        //     ModelManagerSingleton::getInstance()->getModelManager()->getGameObjects());
        window.display();
        DeltaTimeSingleton::getInstance()->getObject()->measure();
    }
}