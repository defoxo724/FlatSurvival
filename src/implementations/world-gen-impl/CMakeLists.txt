add_library(world-gen-impl STATIC 
    "FlatWorldGenerator.cpp"
    "PerlinNoiseWorldGenerator.cpp"
    )
target_include_directories(world-gen-impl PUBLIC . ${perlinnoise_SOURCE_DIR})
target_link_libraries(world-gen-impl PUBLIC world-gen model models)