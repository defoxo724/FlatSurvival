cmake_minimum_required(VERSION 3.15)
project("FlatSurvival")

include("FetchContent")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
)
FetchCOntent_MakeAvailable(
    SFML
)

FetchContent_Declare(
    PerlinNoise
    GIT_REPOSITORY https://github.com/Reputeless/PerlinNoise.git
    GIT_TAG master
)

FetchContent_MakeAvailable(PerlinNoise)

add_subdirectory(src)
