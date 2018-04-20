#include "handgun.h"


handgun::handgun(void) : Card::Card("handgun", 4, 600, 200) {}

string handgun::render(int line){
    
 switch(line){
        case 0: return ".___________.";
        case 1: return "|HANDGUNNER |";
        case 2: return "|    /-\\    |";
        case 3: return "|    \\_/    |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|  600/200  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}