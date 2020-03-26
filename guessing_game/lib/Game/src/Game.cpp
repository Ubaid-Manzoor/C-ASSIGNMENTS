#include <iostream>
#include <Game.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

// Game Class Method Definitions

int Game::guess_number() const{
    srand(time(0));

    return rand()%100;
}

void Game::play(){
    cout<<"Guess a Number"<<endl;
    cin>>player_number;

    if(pcs_number == player_number){
        cout<< "================================YOU WON!!!============================"<<endl;
        return;
    }else if(player_number < pcs_number){
        cout<< "Choise a Greater Number"<<endl;
        play();
    }else{
        cout<< "Choise a Lesser Number"<<endl;
        play();
    }

}

void Game::start_game() {
    cout<<"=========================================================================="<<endl;
    cout<<"==========================LETS START THE GAME============================="<<endl;
    cout<<"=========================================================================="<<endl;
    pcs_number = guess_number();
    cout<<"----------------"<<endl;
    cout<<pcs_number<<endl;
    cout<<"----------------"<<endl;
    play();
}