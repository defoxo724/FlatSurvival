add_library(sfml-health-displayer STATIC "SfmlHealthDisplayer.cpp")
target_include_directories(sfml-health-displayer PUBLIC .)
target_link_libraries(sfml-health-displayer PUBLIC health-displayer)