# message(MESSAGE3)

# add_library(Game Game.cpp)
# message(MESSAGE4)
# add_subdirectory(Game)
# message(MESSAGE5)
# add_subdirectory(Player)
# message(MESSAGE6)

# add_library(Player Player.cpp)

add_executable(main main.cpp)

# target_link_libraries(Player Game)
target_link_libraries(main 
                      Game
                      Player)
