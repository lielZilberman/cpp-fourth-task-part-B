#include "Captain.hpp"
#include "Game.hpp"
#include <string.h>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace coup;
using namespace std;

Captain::Captain(Game &gameID, string name) : Player(gameID, move(name)){
    this->roleOf = "Captain";
}

void Captain::steal( Player &dest){
    if (this->isDead == 1)
    {
        throw invalid_argument("the player is dead");
    }
    if (this->gameID->turn() != this->name)
    {
        throw invalid_argument("wait for your turn");
    }
    if (dest.coinsNum < 2)
    {
        this->coinsNum += dest.coinsNum;
        dest.coinsNum -= dest.coinsNum;
    } else { 
    
    dest.coinsNum -=2;
    this->coinsNum += 2;
    }
    this->whoStolen = dest.name;
    this->gameID->turnId++;
    this->lastAction = "steal";
}

void Captain::block( Player &dest){
    if (this->isDead == 1)
    {
        throw invalid_argument("the player is dead");
    }
    if (dest.lastAction != "steal")
    {
        throw invalid_argument("captain can only block 'steal'");
    }
    this->lastAction = "block";

}