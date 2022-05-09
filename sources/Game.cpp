#include "Game.hpp"
#include "Player.hpp"
#include <string.h>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace coup;


Game::Game(){
    this->turnId = 0;
    this->gameStarted = 0;
}

string Game::turn(){
    while (this->whoPlays[this->turnId % this->whoPlays.size()]->isDead == 1)
    {
        this->turnId++;
    }
    
    return this->whoPlays[this->turnId % this->whoPlays.size()]->name;
    
}

vector<string> Game::players() const{
    vector<string> names;
    for (size_t i = 0; i < this->whoPlays.size(); i++)
    {
        if (this->whoPlays[i]->isDead == 1)
        {
            continue;
        }
        
        names.push_back(this->whoPlays[i]->name);
    }
    
    return names;
}

void Game::push_player(Player *player){
    this->whoPlays.push_back(player);
}

string Game::winner(){
    if (this->whoPlays.size() <= 1)
    {
        throw invalid_argument("only one player!");
    }
    
    int active = 0;
    unsigned int index = 0;
    for (size_t i = 0; i < this->whoPlays.size(); i++)
    {
        if (this->whoPlays[i]->isDead == 0)
        {
            active++;
            if (active > 1)
            {
                throw invalid_argument("the game is still active!");
            }

            index = i;
        }
        
    }
    
    return this->whoPlays[index]->name;
}

