add_library(sfml-camera STATIC "SfmlCamera.cpp")
target_include_directories(sfml-camera PUBLIC .)
target_link_libraries(sfml-camera PUBLIC SFML::Graphics camera)