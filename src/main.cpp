#include "AABBHelper.hpp"
#include "BasicBlock.hpp"
#include "BlockBreaker.hpp"
#include "CameraSingleton.hpp"
#include "DeltaTimeSingleton.hpp"
#include "ExecutablePathSingleton.hpp"
#include "ICamera.hpp"
#include "IHealthDisplayer.hpp"
#include "KeyboardDetectorSingleton.hpp"
#include "LinuxExecutablePath.hpp"
#include "ModelManagerImpl.hpp"
#include "ModelManagerSingleton.hpp"
#include "ModelRendererSingleton.hpp"
#include "MouseDetectorSingleton.hpp"
#include "PerlinNoiseWorldGenerator.hpp"
#include "PlayerGameObjectModel.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"
#include "SfmlColorModelRenderer.hpp"
#include "SfmlDeltaTime.hpp"
#include "SfmlHealthDisplayer.hpp"
#include "SfmlKeyboardDetector.hpp"
#include "SfmlMouseDetector.hpp"
#include "Vec2.hpp"
#include "implementations/backends/sfml/sfml-camera/SfmlCamera.hpp"
#include <SFML/Graphics.hpp>
#include <cstddef>
#include <cstdio>
#include <ctime>
#include <filesystem>
#include <iostream>
#include <memory>

int main()
{

    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML works!");
    window.setFramerateLimit(240);

    KeyboardDetectorSingleton::getInstance()->setObject(std::make_shared<SfmlKeyBoardDetector>());
    ModelRendererSingleton::getInstance()->setObject(std::make_shared<SfmlColorModelRenderer>(window));
    MouseDetectorSingleton::getInstance()->setObject(std::make_shared<SfmlMouseDetector>(window));
    DeltaTimeSingleton::getInstance()->setObject(std::make_shared<SfmlDeltaTime>());
    ExecutablePathSingleton::getInstance()->setObject(std::make_shared<LinuxExecutablePath>());
    CameraSingleton::getInstance()->setObject(std::make_shared<SfmlCamera>(window));

    ModelManagerSingleton::getInstance()->setObject(std::make_shared<ModelManagerImpl>());
    auto go = std::make_shared<PlayerGameObjectModel>();
    ModelManagerSingleton::getInstance()->getObject()->addModel(go);

    BlockBreaker blockBreaker;

    go->setPosition({0, 300});

    sf::Font font{ExecutablePathSingleton::getInstance()->getObject()->get() +
                  "/../../assets/fonts/PixelifySans-Bold.ttf"};
    sf::Text text{font};
    text.setString("XDDD");

    std::shared_ptr<IHealthDisplayer> healthDisplayer = std::make_shared<SfmlHealthDisplayer>(font, window);
    // std::shared_ptr<IWorldGenerator> worldGen = std::make_shared<FlatWorldGenerator>(100, 30, Vec2{100, 500});
    std::shared_ptr<IWorldGenerator> worldGen = std::make_shared<PerlinNoiseWorldGenerator>(500, Vec2{0, 2000});
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

        window.clear(sf::Color::Blue);
        window.draw(text);
        ModelManagerSingleton::getInstance()->getObject()->update();
        ModelRendererSingleton::getInstance()->getObject()->render(
            ModelManagerSingleton::getInstance()->getObject()->getGameObjects());

        for (auto &el : ModelManagerSingleton::getInstance()->getObject()->getGameObjects())
        {
            if (el->getObjectName() == "PLAYER")
            {
                CameraSingleton::getInstance()->getObject()->setCenter(el->getPosition());
                break;
            }
        }
        blockBreaker.breakBlocks(window);
        // healthDisplayer->displayGameObjectsHealth(
        //     ModelManagerSingleton::getInstance()->getModelManager()->getGameObjects());

        // Update title
        std::string title =
            "FlatSurvival FPS: " + std::to_string(1 / DeltaTimeSingleton::getInstance()->getObject()->getDeltaTime());
        window.setTitle(title);
        window.display();
        DeltaTimeSingleton::getInstance()->getObject()->measure();
    }
}