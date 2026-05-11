add_library(model-renderer INTERFACE)
target_include_directories(model-renderer INTERFACE .)
target_link_libraries(model-renderer INTERFACE model)