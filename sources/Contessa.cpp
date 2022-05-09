#include "Contessa.hpp"
#include "Game.hpp"
#include <string.h>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace coup;
using namespace std;

Contessa::Contessa(Game &gameID, string name) : Player(gameID, move(name)){
    this->roleOf = "Contessa";
}

void Contessa::block(Player &dest){
    if (this->isDead == 1)
    {
        throw invalid_argument("the player is dead");
    }
    if (dest.lastAction != "eliminate")
    {
        throw invalid_argument("contessa can only block 'eliminate'");
    }
    for (size_t i = 0; i < this->gameID->whoPlays.size(); i++)
    {
        if (this->gameID->whoPlays[i]->name == dest.whoKilled)
        {
            this->gameID->whoPlays[i]->isDead = 0;
            break;
        }
    }
    
    this->lastAction = "block";

}