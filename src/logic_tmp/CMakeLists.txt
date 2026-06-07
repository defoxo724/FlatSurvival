add_library(logic_tmp STATIC "BlockBreaker.cpp")
target_include_directories(logic_tmp  PUBLIC .)
target_link_libraries(logic_tmp PUBLIC 
    model 
    global 
    utils
    SFML::Graphics      
)