#include "Assassin.hpp"
#include "Game.hpp"
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>

using namespace coup;
using namespace std;

const int MIN_FOR_COUP = 7;

Assassin::Assassin(Game &gameID, string name) : Player(gameID, move(name)){
    this->roleOf = "Assassin";
}

void Assassin::coup(Player &dest){
    if (this->isDead == 1)
    {
        throw invalid_argument("the player is dead");
    }
    if (this->gameID->turn() != this->name)
    {
        throw invalid_argument("wait for your turn");
    }

    if (dest.isDead == 1)
    {
        throw invalid_argument("you can't coup a dead player");
    }

    if (this->coins() < 3){
        throw invalid_argument("not enough coins");
    }

    if (this->coins() >= MIN_FOR_COUP)
    {
        this->coinsNum -= MIN_FOR_COUP;
        this->lastAction = "coup";
    } else {
        this->whoKilled = dest.name;
        this->coinsNum -= 3;
        this->lastAction = "eliminate";
    }
    dest.isDead = 1;
    this->gameID->turnId++;
}