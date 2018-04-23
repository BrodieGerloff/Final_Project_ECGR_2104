#include "sword.h"

Sword::Sword(void) : Card::Card("Sword", 2, 300, 200) {}

string Sword::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Sword      |";
        case 2: return "|     /\\    |";
        case 3: return "|     ||    |";
        case 4: return "|     ||    |";
        case 5: return "|     ||    |";
        case 6: return "|  300/200  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}