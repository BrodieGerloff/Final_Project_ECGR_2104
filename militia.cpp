#include "militia.h"

Militia::Militia(void) : Card::Card("Militia", 1, 100, 300) {}

string Militia::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|1) MILITIA |";
        case 2: return "|  /-----\\  |";
        case 3: return "|  |  |  |  |";
        case 4: return "|  |  |  |  |";
        case 5: return "|  \\ ___ /  |";
        case 6: return "|  100/300  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}