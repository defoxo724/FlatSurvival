add_executable(${PROJECT_NAME} main.cpp Blocks.cpp)


target_include_directories(${PROJECT_NAME} PUBLIC . ${perlinnoise_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC 
    SFML::Graphics      
)
