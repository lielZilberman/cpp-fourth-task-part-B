#pragma once
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

namespace coup{
class Game;
   class Player
   {
   public:
       string name;
       int coinsNum;
       int isDead;
       string whoKilled;
       string whoStolen;
       Game *gameID;
       string lastAction;
       string roleOf;
       Player(Game &gameID, string name);
       void income();
       void foreign_aid();
       void coup(Player &dest);
       string role() const;
       int coins() const; 
   };
}