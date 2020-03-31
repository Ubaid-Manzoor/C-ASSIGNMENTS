add_subdirectory(igg_image)

add_executable(main main.cpp)

target_link_libraries(main image ${LIBRARY_OUTPUT_PATH}/libio_tools.so)
