add_library(sfml-model-renderer STATIC "SfmlColorModelRenderer.cpp")
target_include_directories(sfml-model-renderer PUBLIC .)
target_link_libraries(sfml-model-renderer PUBLIC model SFML::Graphics model-renderer)