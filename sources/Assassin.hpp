#include "Player.hpp"
#include <string.h>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace coup{
    class Assassin : public Player
    {
    public:
        Assassin(Game &gameID, string name);
        void coup(Player &dest);
    };
    
    
}