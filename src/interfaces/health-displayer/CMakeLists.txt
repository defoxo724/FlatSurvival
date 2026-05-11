add_library(health-displayer INTERFACE)
target_include_directories(health-displayer INTERFACE .)
target_link_libraries(health-displayer INTERFACE model SFML::Graphics )