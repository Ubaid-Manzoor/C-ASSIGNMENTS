
#Giving Project a Name
project(guessing_game)

#Mentioning Version of CMake
cmake_minimum_required(VERSION 3.0)

#Where to Find the Library
# message(MESSAGE1)
# include_directories(src)
# message(MESSAGE1.5)

add_subdirectory(lib)
add_subdirectory(src)
# message(MESSAGE2)

include_directories(lib)


enable_testing()

add_subdirectory(tests)