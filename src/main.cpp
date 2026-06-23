#include "Blocks.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"
#include "WorldGenerator.hpp"
#include "global.hpp"
#include <PerlinNoise.hpp>
#include <array>
#include <cstdint>
#include <sys/types.h>

int main()
{
    WorldGenerator generator;
    generator.generateWorld2();
    srand(time(NULL));
    sf::RectangleShape cursor{sf::Vector2f(BLOCK_SIZE_IN_PIXELS, BLOCK_SIZE_IN_PIXELS)};
    cursor.setFillColor(sf::Color(0, 0, 0, 0));
    cursor.setOutlineColor(sf::Color::Red);
    cursor.setOutlineThickness(1);

    window.setFramerateLimit(60);
    // generateWorld();
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        cursor.setPosition(
            sf::Vector2f((sf::Mouse::getPosition(window).x / BLOCK_SIZE_IN_PIXELS) * BLOCK_SIZE_IN_PIXELS,
                         (sf::Mouse::getPosition(window).y / BLOCK_SIZE_IN_PIXELS) * BLOCK_SIZE_IN_PIXELS));

        /* Destroying blocks*/
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            std::uint32_t x = (sf::Mouse::getPosition(window).x / BLOCK_SIZE_IN_PIXELS);
            std::uint32_t y = (sf::Mouse::getPosition(window).y / BLOCK_SIZE_IN_PIXELS);

            blockArray.at(x).at(y) = Blocks::AIR;
        }

        // Block rendering
        sf::RectangleShape blockDrawer;
        blockDrawer.setSize(sf::Vector2f{BLOCK_SIZE_IN_PIXELS, BLOCK_SIZE_IN_PIXELS});
        for (int x = 0; x < blockArray.size(); x++)
        {
            for (int y = 0; y < blockArray[x].size(); y++)
            {
                blockDrawer.setPosition(sf::Vector2f(x * BLOCK_SIZE_IN_PIXELS, y * BLOCK_SIZE_IN_PIXELS));
                blockDrawer.setFillColor(blockArray.at(x).at(y).renderedColor);
                window.draw(blockDrawer);
            }
        }
        window.draw(cursor);

        window.display();
        window.clear();
    }
}