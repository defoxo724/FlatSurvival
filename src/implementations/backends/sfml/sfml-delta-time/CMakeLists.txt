add_library(sfml-delta-time STATIC "SfmlDeltaTime.cpp")
target_include_directories(sfml-delta-time PUBLIC .)
target_link_libraries(sfml-delta-time PUBLIC SFML::Graphics delta-time)