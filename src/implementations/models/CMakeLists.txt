add_library(models STATIC 
    "AGameObject.cpp"
    "entities/PlayerGameObjectModel.cpp" 
    "blocks/GrassGameObjectModel.cpp"
    "blocks/SandGameObjectModel.cpp"
    "blocks/StoneGameObjectModel.cpp"
    "blocks/BasicBlock.cpp"
)
target_include_directories(models PUBLIC .)
target_include_directories(models PUBLIC blocks)
target_include_directories(models PUBLIC entities)
target_link_libraries(models PUBLIC model global sfml-keyboard delta-time)