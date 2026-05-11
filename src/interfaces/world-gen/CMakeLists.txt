add_library(world-gen INTERFACE)
target_include_directories(world-gen INTERFACE .)
target_link_libraries(world-gen INTERFACE model)