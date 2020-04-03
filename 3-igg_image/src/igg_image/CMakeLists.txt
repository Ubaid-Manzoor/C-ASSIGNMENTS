add_subdirectory(io_strategies)

# TODO: create image library from image.cpp.
add_library(image image.cpp image.h)

# TODO: link image library to any other libraries if needed.

target_link_libraries(image strategies)