add_subdirectory(implementations)
add_subdirectory(interfaces)

add_subdirectory(utils)
add_subdirectory(global)



add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE 
    SFML::Graphics  
    model-manager-impl 
    utils 
    sfml-model-renderer 
    world-gen-impl 
    global 
    sfml-mouse 
    sfml-health-displayer
    model
    models
)

