add_library(model-manager-impl STATIC "ModelManagerImpl.cpp")
target_include_directories(model-manager-impl PUBLIC .)
target_link_libraries(model-manager-impl PUBLIC model model-manager)