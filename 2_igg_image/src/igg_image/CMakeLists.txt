#################### Import the 'io_tools' library here ########################

#################### Create a library 'image' below this line ##################

add_library(image image.cpp image.h)

target_link_libraries(image ${LIBRARY_OUTPUT_PATH}/libio_tools.so)
