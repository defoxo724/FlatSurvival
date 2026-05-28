#include "AABBHelper.hpp"
#include "BasicBlock.hpp"
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

        window.clear();
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

        /*
        TODO: Ten kod jest tymczasowy, zaimplementować system niszczenia plików tutaj i potem wydzielić go do osobnej
        klasy/przemyśleć co i jak
        TODO: Zmienić obszar zamiast prostokątów na koła
         */
        sf::Vector2i windowPos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePos = window.mapPixelToCoords(windowPos);

        // Pixels TODO: Zmienić potem na obliczanie tej ilości na dole razy wielkość bloku
        const int AREA = 50;

        const int MINING_AREA = 200;

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

        // healthDisplayer->displayGameObjectsHealth(
        //     ModelManagerSingleton::getInstance()->getModelManager()->getGameObjects());
        window.display();
        DeltaTimeSingleton::getInstance()->getObject()->measure();
    }
}