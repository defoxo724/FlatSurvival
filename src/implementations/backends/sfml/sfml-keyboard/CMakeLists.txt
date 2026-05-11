add_library(sfml-keyboard STATIC "SfmlKeyboardDetector.cpp")
target_include_directories(sfml-keyboard   PUBLIC .)
target_link_libraries(sfml-keyboard  PUBLIC keyboard SFML::Graphics)