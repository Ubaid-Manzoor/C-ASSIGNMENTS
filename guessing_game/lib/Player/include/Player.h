#pragma once

#include <iostream>
#include <Game.h>

using std::string;

class Player{
public:
    Player(string);
    void play_game(Game game) const;
private:
    string player_name;
};