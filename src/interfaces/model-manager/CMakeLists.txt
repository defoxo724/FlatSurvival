add_library(model-manager INTERFACE)
target_include_directories(model-manager INTERFACE .)
target_link_libraries(model-manager INTERFACE model)