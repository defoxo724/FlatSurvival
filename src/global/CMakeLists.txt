add_library(global INTERFACE)
target_include_directories(global INTERFACE .)
target_link_libraries(global INTERFACE 
    model-manager 
    keyboard 
    sfml-keyboard 
    model-renderer 
    delta-time 
    sfml-delta-time 
    mouse 
    filesystem
    camera
)
