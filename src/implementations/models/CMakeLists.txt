add_library(models STATIC 
    "AGameObject.cpp"
    "PlayerGameObjectModel.cpp" 
    "GrassGameObjectModel.cpp"
    "SandGameObjectModel.cpp"
    "StoneGameObjectModel.cpp"
)
target_include_directories(models PUBLIC .)
target_link_libraries(models PUBLIC model global sfml-keyboard delta-time)