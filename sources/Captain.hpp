#include "Player.hpp"
#include <string.h>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace coup{
    class Captain : public Player
    {
    public:
        Captain(Game &gameID, string name);
        void steal( Player &dest);
        void block( Player &dest);
    };
    
    
    
}