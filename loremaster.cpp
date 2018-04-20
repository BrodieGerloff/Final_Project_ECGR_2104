#include "loremaster.h"


loremaster:loremaster(void) : Card::Card("Loremaster", 4, 500, 400) {}

string loremaster::render(int line){
    
 switch(line){
        case 0: return ".___________.";
        case 1: return "|Loremaster |";
        case 2: return "|     |+|   |";
        case 3: return "|     |+|   |";
        case 4: return "|     |+|   |";
        case 5: return "|     |+|   |";
        case 6: return "|  400/500  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
