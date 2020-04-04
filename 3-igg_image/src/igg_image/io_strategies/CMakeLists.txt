add_library(strategies
            # TODO: Add other files here when needed.
            png_strategy.cpp
            dummy_strategy.cpp
            ppm_strategy.cpp)
# TODO: link strategies against needed libraries.
find_package(PNG)

message(MESSAGE : ${PNG_INCLUDE_DIRS})
message(MESSAGE : ${PNG_LIBRARIES})

target_link_libraries(strategies ${PNG_LIBRARIES})

