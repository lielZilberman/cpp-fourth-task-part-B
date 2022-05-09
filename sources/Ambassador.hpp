#include "Player.hpp"
#include <string.h>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace coup{
    class Ambassador : public Player
    {
    public:
        Ambassador(Game &gameID, string name);
        void transfer(Player &src, Player &dest);
        void block(Player &dest);
    };   
}