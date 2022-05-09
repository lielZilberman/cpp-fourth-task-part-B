#include "Player.hpp"
#include <string.h>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace coup{
    class Duke : public Player
    {
    public:
        Duke(Game &gameID, string name);
        void block(Player &dest);
        void tax();
    };
    
    
    
}