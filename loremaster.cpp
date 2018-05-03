#include "loremaster.h"


Loremaster::Loremaster(void) : Card::Card("Loremaster", 4, 500, 400) {}

string Loremaster::render(int line){
    
 switch(line){
        case 0: return ".___________.";
        case 1: return "|4) LOREMSTR|";
        case 2: return "|     |+|   |";
        case 3: return "|     |+|   |";
        case 4: return "|     |+|   |";
        case 5: return "|     |+|   |";
        case 6: return "|  500/400  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
