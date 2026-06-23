#pragma once

#include "Biome.hpp"
#include "Biomes.hpp"
#include "global.hpp"
#include <PerlinNoise.hpp>
#include <array>
#include <sys/types.h>
#include <vector>

class WorldGenerator
{
  public:
    void generateWorld2()
    {
        // Zmienne
        const siv::PerlinNoise terrainNoise{static_cast<unsigned int>(rand())};

        // Lista biomów do losowania
        std::vector<Biome> availableBiomes{Biomes::PLAINS, Biomes::DESERT, Biomes::HILLS};

        // Ustawienia Perlin noise
        const double terrainFrequency = 0.08;

        // Ile bloków ma trwać przejście między biomami
        const int BIOME_TRANSITION_WIDTH = 8;

        // Ostatnia wysokość poprzedniego biomu
        int lastTerrainHeight = -1;

        for (int x = 0; x < WORLD_WIDTH; x++)
        {
            // Losowanie biomu
            int biomeNum = rand() % availableBiomes.size();
            Biome randBiome = availableBiomes.at(biomeNum);

            // Losowanie rozmiaru biomu z minimalnej i maksymalnej szerokości biomu
            int biomeWidth = rand() % (randBiome.maxWidth - randBiome.minWidth + 1) + randBiome.minWidth;

            // Wysokość, od której zaczyna się przejście
            int transitionStartHeight = lastTerrainHeight;

            // Generowanie biomu
            for (int i = 0; (i < biomeWidth && x + i < WORLD_WIDTH); i++)
            {
                int currentX = x + i;

                // Perlin noise zwraca wartość 0.0 - 1.0
                double noiseValue = terrainNoise.noise2D_01(currentX * terrainFrequency, 0.0);

                // Zamiana noise na wysokość z zakresu minHeight - maxHeight
                int targetHeight =
                    randBiome.minHeight + static_cast<int>(noiseValue * (randBiome.maxHeight - randBiome.minHeight));

                // Zabezpieczenie wysokości
                if (targetHeight < 1)
                    targetHeight = 1;

                if (targetHeight > WORLD_HEIGHT)
                    targetHeight = WORLD_HEIGHT;

                int terrainHeight = targetHeight;

                // Łagodne przejście z poprzedniego biomu do aktualnego
                if (transitionStartHeight != -1 && i < BIOME_TRANSITION_WIDTH)
                {
                    double t = static_cast<double>(i) / BIOME_TRANSITION_WIDTH;

                    terrainHeight =
                        transitionStartHeight + static_cast<int>((targetHeight - transitionStartHeight) * t);
                }

                // Wysokość
                for (int y = 0; y < terrainHeight; y++)
                {
                    blockArray.at(currentX).at(WORLD_HEIGHT - y - 1) = randBiome.block;
                }

                // Zapamiętanie ostatniej wysokości
                lastTerrainHeight = terrainHeight;
            }

            x += biomeWidth - 1;
        }
    }
};