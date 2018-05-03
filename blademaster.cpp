#include "blademaster.h"

Blademaster::Blademaster(void) : Card::Card("Blademaster", 4, 500, 400) {}

string Blademaster::render(int line){
    
 switch(line){
        case 0: return ".___________.";
        case 1: return "|4) BLADMSTR|";
        case 2: return "|     ||    |";
        case 3: return "|     ||    |";
        case 4: return "|     ||    |";
        case 5: return "|     ||    |";
        case 6: return "|  500/400  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}