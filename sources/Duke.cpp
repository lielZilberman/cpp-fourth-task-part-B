#include "Duke.hpp"
#include "Game.hpp"
#include <string.h>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace coup;
using namespace std;

Duke::Duke(Game &gameID, string name) : Player(gameID, move(name)){
    this->roleOf = "Duke";
}

void Duke::block(Player &dest){
    if (this->isDead == 1)
    {
        throw invalid_argument("the player is dead");
    }
    if (dest.lastAction != "foreign")
    {
        throw invalid_argument("duke can only block 'foreign'");
    }
    dest.coinsNum -= 2;
    this->lastAction = "block";
}

void Duke::tax(){
    if (this->isDead == 1)
    {
        throw invalid_argument("the player is dead");
    }
    if (this->gameID->turn() != this->name)
    {
        throw invalid_argument("wait for your turn");
    }
    this->coinsNum += 3;
    this->gameID->turnId++;
    this->lastAction = "tax";
}