#include "hammer.h"


hammer::hammer(void) : Card::Card("Hammer", 3, 500, 200) {}

string Hammer::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Hammer     |";
        case 2: return "|   _____   |";
        case 3: return "|  |_____|  |";
        case 4: return "|     |     |";
        case 5: return "|     |     |";
        case 6: return "|  500/200  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}