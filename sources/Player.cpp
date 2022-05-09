#include "Player.hpp"
#include "Game.hpp"
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace coup;
using namespace std;

const int MIN_FOR_COUP = 7;
const int MAX_TEAM_SIZE = 6;
const int MAX_COINS_FOR_COUP = 10;

Player::Player(Game &gameID, string name){
    this->name = move(name);
    this->gameID = &gameID;
    if (this->gameID->gameStarted == 1)
    {
        throw invalid_argument("can't add player during the game");
    }
    
    this->gameID->push_player(this);
    if (this->gameID->whoPlays.size() > MAX_TEAM_SIZE)
    {
        throw invalid_argument("too many players");
    }
    
    this->coinsNum = 0;
    this-> isDead = 0;
    this->whoKilled = "";
    this->whoStolen = "";
}

int Player::coins() const{
    return this->coinsNum;
}

void Player::coup(Player &dest){
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
    
    if (this->coins() < MIN_FOR_COUP)
    {
        throw invalid_argument("not enough coins");
    }
    dest.isDead = 1;
    this->gameID->turnId++;
    this->coinsNum -= MIN_FOR_COUP;
    this->lastAction = "coup";
}

void Player::foreign_aid(){
    if (this->isDead == 1)
    {
        throw invalid_argument("the player is dead");
    }
    if (this->gameID->turn() != this->name)
    {
        throw invalid_argument("wait for your turn");
    }

    if (this->coins() >= MAX_COINS_FOR_COUP)
    {
        throw invalid_argument("must coup!");
    }

    if (this->gameID->whoPlays.size() <= 1)
    {
        throw invalid_argument("only one player");
    }
    
    this->coinsNum += 2;
    this->gameID->turnId++;
    this->lastAction = "foreign";
}

string Player::role() const{
    return this->roleOf;
}

void Player::income(){
    if (this->isDead == 1)
    {
        throw invalid_argument("the player is dead");
    }
    if (this->gameID->turn() != this->name)
    {
        throw invalid_argument("wait for your turn");
    }
    if (this->gameID->whoPlays.size() <= 1)
    {
        throw invalid_argument("only one player");
    }
    this->gameID->gameStarted = 1;
    this->coinsNum++;
    this->gameID->turnId++;
    this->lastAction = "income";
}