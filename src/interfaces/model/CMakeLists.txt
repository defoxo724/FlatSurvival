add_library(model INTERFACE)
target_include_directories(model INTERFACE .)
target_link_libraries(model INTERFACE utils)