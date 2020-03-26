add_library(Player src/Player.cpp include/Player.h)
            
            
target_include_directories(Player PUBLIC include)
target_link_libraries(Player Game)
