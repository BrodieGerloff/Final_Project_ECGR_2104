#include "spear.h"

spear :: card(){
	manaCost = 1;
	attack = 300;
	defense = 100
}

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