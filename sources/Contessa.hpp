#include "Player.hpp"
#include <string.h>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace coup{
   class Contessa : public Player
   {
   public:
       Contessa(Game &gameID, string name);
       void block( Player &dest);
   };
   
   
   

}