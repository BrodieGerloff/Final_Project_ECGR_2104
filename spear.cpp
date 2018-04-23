#include "spear.h"

Spear::Spear(void) : Card::Card("Spear", 1, 300, 100) {}

string Spear::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Spear      |";
        case 2: return "|     ^     |";
        case 3: return "|     |     |";
        case 4: return "|     |     |";
        case 5: return "|     |     |";
        case 6: return "|  300/100  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}