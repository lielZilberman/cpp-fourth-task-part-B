#include "Ambassador.hpp"
#include "Game.hpp"
#include <string.h>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace coup;
using namespace std;
 
Ambassador::Ambassador(Game &gameID, string name) : Player(gameID, move(name)){
    this->roleOf = "Ambassador";
}

void Ambassador::transfer(Player &src, Player &dest){
    if (this->isDead == 1)
    {
        throw invalid_argument("the player is dead");
    }
    if (this->gameID->turn() != this->name)
    {
        throw invalid_argument("wait for your turn");
    }
    if (src.coins() < 1)
    {
        throw invalid_argument("can't transfer 0 coins");
    }
    src.coinsNum--;
    dest.coinsNum++;
    this->gameID->turnId++;
    this->lastAction = "transfer";
}

void Ambassador::block( Player &dest){
    if (this->isDead == 1)
    {
        throw invalid_argument("the player is dead");
    }
    if (dest.lastAction != "steal")
    {
        throw invalid_argument("ambassador can only block 'steal'");
    }

    for (size_t i = 0; i < this->gameID->whoPlays.size(); i++)
    {
        if (this->gameID->whoPlays[i]->name == dest.whoStolen)
        {
            this->gameID->whoPlays[i]->coinsNum += 2;
            dest.coinsNum -= 2;
            break;
        }
    }


    
    this->lastAction = "block";

}