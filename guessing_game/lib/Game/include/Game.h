#pragma once

class Game{
public:
    void start_game();
    int guess_number() const;
    void play();
private:
    int pcs_number{0};
    int player_number;
};