add_library(filesystem-impl STATIC "LinuxExecutablePath.cpp")
target_include_directories(filesystem-impl  PUBLIC .)
target_link_libraries(filesystem-impl PUBLIC filesystem)