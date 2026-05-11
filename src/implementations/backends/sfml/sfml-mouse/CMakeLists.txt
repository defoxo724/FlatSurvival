add_library(sfml-mouse STATIC "SfmlMouseDetector.cpp")
target_include_directories(sfml-mouse PUBLIC .)
target_link_libraries(sfml-mouse  PUBLIC mouse SFML::Graphics utils)