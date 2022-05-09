#pragma once
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;
namespace coup{
class Player;
class Game
{   
public:
   Game();
   int gameStarted;
   void push_player(Player *player);
   vector<Player*> whoPlays;
   unsigned int turnId;
   string turn();
   vector<string> players() const;
   string winner();
};
}


