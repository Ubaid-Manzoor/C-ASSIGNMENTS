#include <Player.h>
// Player Class Method Definitions

Player::Player(string name):player_name{name}{}
void Player::play_game(Game game) const{
    game.start_game();
}