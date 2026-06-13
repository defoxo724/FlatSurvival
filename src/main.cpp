#include "Blocks.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <vector>

int main()
{
    std::vector<std::vector<Block>> blocks{
        {Blocks::GRASS, Blocks::GRASS, Blocks::GRASS, Blocks::GRASS, Blocks::GRASS, Blocks::GRASS, Blocks::GRASS,
         Blocks::GRASS, Blocks::GRASS, Blocks::GRASS},
    };
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML works!");

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        const int BLOCK_SIZE_IN_PIXELS = 32;

        sf::RectangleShape blockDrawer;

        // Prawdopodobnie źle wyświetla bloki na odwrót
        blockDrawer.setSize(sf::Vector2f{BLOCK_SIZE_IN_PIXELS, BLOCK_SIZE_IN_PIXELS});
        for (int i = 0; i < blocks.size(); i++)
        {
            for (int j = 0; j < blocks[i].size(); j++)
            {
                blockDrawer.setPosition(sf::Vector2f(i * BLOCK_SIZE_IN_PIXELS, j * BLOCK_SIZE_IN_PIXELS));
                if (blocks.at(i).at(j).textureName == "grass")
                {
                    blockDrawer.setFillColor(sf::Color::Green);
                }
                else if (blocks.at(i).at(j).textureName == "sand")
                {
                    blockDrawer.setFillColor(sf::Color::Yellow);
                }
                else
                {
                    continue;
                }
                window.draw(blockDrawer);
            }
        }

        window.display();
    }
}